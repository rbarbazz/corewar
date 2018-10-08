/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:11:37 by msamak            #+#    #+#             */
/*   Updated: 2018/10/08 14:30:31 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	get_ocp(t_global *info, t_process *process)
{
	char	*value;
	char	ocp;

	value = get_value_at_position(info->map, process->position, 1);
	ocp = value[3];
	ft_strdel(&value);
	return (ocp);
}

void	increase_position(t_process *process)
{
	process->position++;
	process->position = process->position % 4096;
}

/*
** *****************************************************************************
** gets the current opcode and check if it is valid
** *****************************************************************************
*/

void	get_op(t_global *info, t_process *process)
{
	int		op;
	char	*value;
	char	ocp;

	value = get_value_at_position(info->map, process->position, 1);
	op = tab_to_int(value);
	ft_strdel(&value);
	if ((process->cycle_left = get_cycle_from_op(op, process)) == -1)
	{
		increase_position(process);
		return ;
	}
	process->cycle_left--;
	if (process->ocp)
		ocp = get_ocp(info, process);
}
