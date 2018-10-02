/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:32:26 by msamak            #+#    #+#             */
/*   Updated: 2018/10/02 19:09:23 by msamak           ###   ########.fr       */
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
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
	{
		ft_printf("Too many champions\n");
		exit(TOO_MANY_ARGS);
	}
	if (error_code == FILE_EMPTY)
	{
		ft_printf("Champion can't be empty\n");
		exit(FILE_EMPTY);
	}
	if (error_code == READ_FILE_ERROR)
		exit(READ_FILE_ERROR);
	if (error_code == MALLOC_ERROR)
	{
		ft_printf("Malloc : Error - [Protected]\n");
		exit(MALLOC_ERROR);
	}
	if (error_code == INVALID_MAGIC)
	{
		ft_printf("Invalid COREWAR_EXEC_MAGIC\n");
		exit(INVALID_MAGIC);
	}
	free_player();
	exit(0);
}
