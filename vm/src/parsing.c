/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:43:40 by msamak            #+#    #+#             */
/*   Updated: 2018/10/02 19:13:49 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*uitoa_d(unsigned int dec)
{
	char			size[5];
	unsigned int	len;

	len = 4;
	size[len] = 0;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	return (ft_strndup(size, 4));
}

int		check_magic(char *file)
{
	char	*exec;
	int		i;

	exec = uitoa_d(COREWAR_EXEC_MAGIC);
	i = 0;
	while (i < 4)
	{
		if (exec[i] != file[i])
		{
			ft_strdel(&exec);
			return (1);
		}
		i++;
	}
	ft_strdel(&exec);
	return (0);
}

int				tab_to_int(char *str)
{
	int res;

	res = 0;
	res = res | str[3];
	res = res | (str[2] << 8);
	res = res | (str[1] << 16);
	res = res | (str[0] << 24);
	return (res);
}

int				init_player(t_global *info, char *file)
{
	t_player	*new;
	t_player	*tmp;
	char		*command_size;

	tmp = info->player;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_player*)ft_memalloc(sizeof(t_player))))
		exit_corewar(MALLOC_ERROR);
	if (!(new->name = ft_strndup(file + 4, PROG_NAME_LENGTH)))
		exit_corewar(MALLOC_ERROR);
	if (!(command_size = ft_strndup(file + 8 + PROG_NAME_LENGTH, 4)))
		exit_corewar(MALLOC_ERROR);
	new->command_size = tab_to_int(command_size);
	ft_strdel(&command_size);
	if (!(new->comment = ft_strndup(file + 12 + PROG_NAME_LENGTH, COMMENT_LENGTH)))
		exit_corewar(MALLOC_ERROR);
	if (!tmp)
		info->player = new;
	else
		tmp->next = new;
	return (0);
}

int		check_champ(t_global *info, char *filename)
{
	char	*file;
	int		fd;

	fd = open_file(filename);
	file = read_file(fd, filename);
	xxd(file, FILE_LEN_MAX);
	if (check_magic(file) == 1)
	{
		ft_strdel(&file);
		close(fd);
		exit_corewar(INVALID_MAGIC);
	}
	init_player(info, file);
	print_player(info);
	close(fd);
	ft_strdel(&file);
	return (0);
}

int		check_visual(t_global *info, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			info->visual = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_args(t_global *info, int argc, char **argv)
{
	int i;

	i = 1;
	check_visual(info, argc, argv);
	if ((info->visual == 1 && argc > 6) || (info->visual == 0 && argc > 5))
		exit_corewar(TOO_MANY_ARGS);
	while (i < argc)
	{
		if (!ft_strequ(argv[i], "-n"))
			if (check_champ(info, argv[i]) == 1)
				exit_corewar(1);
		i++;
	}
	return (0);
}
