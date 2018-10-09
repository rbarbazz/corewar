/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:11:37 by msamak            #+#    #+#             */
/*   Updated: 2018/10/09 12:08:05 by rbarbazz         ###   ########.fr       */
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

void	increase_position(t_process *process, int add)
{
	process->position += add;
	process->position = process->position % MEM_SIZE;
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

	ocp = 0;
	value = get_value_at_position(info->map, process->position, 1);
	op = tab_to_int(value);
	ft_strdel(&value);
	if ((process->cycle_left = get_data_from_op(op, process)) == -1)
	{
		increase_position(process, 1);
		return ;
	}
	process->cycle_left--;
	if (process->curr_op.has_ocp)
		ocp = get_ocp(info, process);
	get_op_param(info, process, ocp);
	//op_function(info, process, op)
}
