/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:43:40 by msamak            #+#    #+#             */
/*   Updated: 2018/10/03 13:53:23 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
