/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:43:40 by msamak            #+#    #+#             */
/*   Updated: 2018/10/08 17:02:52 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** checks if the file exist and is provided with the right exec magic
** *****************************************************************************
*/

static int	check_champ(t_global *info, char *filename)
{
	char	*file;
	int		fd;

	fd = open_file(filename);
	file = read_file(fd, filename);
	//Debug
	//xxd(file, FILE_LEN_MAX);
	if (check_magic(file))
	{
		ft_strdel(&file);
		close_file(fd);
		exit_corewar(INVALID_MAGIC);
	}
	init_player(info, file);
	//Debug
	//print_player(info);
	close_file(fd);
	ft_strdel(&file);
	return (0);
}

/*
** *****************************************************************************
** look for the -dump option
** check if a null or positive number is provided
** *****************************************************************************
*/

static int	check_dump(t_global *info, int *i, char **argv)
{
	unsigned long long	nb;

	if (ft_strequ(argv[*i], "-dump"))
	{
		if (!argv[*i + 1] || argv[*i + 1][0] == '-' || !is_number(argv[*i + 1]))
			exit_corewar(USAGE_ERROR);
		if ((nb = atoull(argv[*i + 1])) > UINT_MAX)
			nb = UINT_MAX;
		info->clock.dump = (unsigned int)nb;
		info->dump = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

/*
** *****************************************************************************
** look for the -v option
** *****************************************************************************
*/

static int	check_visual(t_global *info, char *arg)
{
	if (ft_strequ(arg, "-v"))
	{
		info->visual = 1;
		return (1);
	}
	return (0);
}

/*
** *****************************************************************************
** check how many champions are provided and the options
** *****************************************************************************
*/

int			check_args(t_global *info, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!check_visual(info, argv[i]) && !check_dump(info, &i, argv))
			check_champ(info, argv[i]);
		i++;
	}
	if (info->player_count > 4)
		exit_corewar(TOO_MANY_ARGS);
	else if (info->player_count < 1)
		exit_corewar(NO_CHAMP);
	return (0);
}
