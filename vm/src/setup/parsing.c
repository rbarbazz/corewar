/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:43:40 by msamak            #+#    #+#             */
/*   Updated: 2018/10/08 14:16:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** checks if the file exist and is provided with the right exec magic
** *****************************************************************************
*/

int		check_champ(t_global *info, char *filename)
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
** look for the -n option
** *****************************************************************************
*/

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

/*
** *****************************************************************************
** check how many champions are provided and the options
** *****************************************************************************
*/

int		check_args(t_global *info, int argc, char **argv)
{
	int i;

	i = 1;
	check_visual(info, argc, argv);
	while (i < argc)
	{
		if (!ft_strequ(argv[i], "-n"))
			check_champ(info, argv[i]);
		i++;
	}
	if (info->player_count > 4)
		exit_corewar(TOO_MANY_ARGS);
	if (info->player_count < 1)
		exit_corewar(NO_CHAMP);
	return (0);
}
