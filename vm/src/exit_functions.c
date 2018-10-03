/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:32:26 by msamak            #+#    #+#             */
/*   Updated: 2018/10/03 16:22:36 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_player(void)
{
	t_global *info;
	t_player *tmp;
	t_player *save;

	info = get_global();
	tmp = info->player;
	while (tmp)
	{
		save = tmp->next;
		ft_strdel(&tmp->name);
		ft_strdel(&tmp->comment);
		ft_strdel(&tmp->command);
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

void		free_map_list(void)
{
	t_global *info;
	t_map *tmp;
	t_map *save;

	info = get_global();
	tmp = info->map_list;
	while (tmp)
	{
		save = tmp->next;
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
	{
		ft_printf("[ERROR] %d : Too many champions\n", error_code);
		exit(TOO_MANY_ARGS);
	}
	if (error_code == FILE_EMPTY)
	{
		ft_printf("[ERROR] %d : Champion can't be empty\n", error_code);
		exit(FILE_EMPTY);
	}
	if (error_code == READ_FILE_ERROR)
		exit(READ_FILE_ERROR);
	if (error_code == MALLOC_ERROR)
	{
		ft_printf("[ERROR] %d : Malloc : Error - [Protected]\n", error_code);
		exit(MALLOC_ERROR);
	}
	if (error_code == INVALID_MAGIC)
	{
		ft_printf("[ERROR] %d : Invalid COREWAR_EXEC_MAGIC\n", error_code);
		exit(INVALID_MAGIC);
	}
	if (error_code == COMMAND_LENGTH_NOT_CORRESPOND)
	{
		ft_printf("[ERROR] %d : code size that differ from what its header says\n", error_code);
		exit(COMMAND_LENGTH_NOT_CORRESPOND);
	}
	free_player();
	free_map_list();
	exit(0);
}
