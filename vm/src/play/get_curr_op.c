/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:11:37 by msamak            #+#    #+#             */
/*   Updated: 2018/10/09 18:35:14 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	get_ocp(t_global *info, t_process *process)
{
	char			*value;
	unsigned char	ocp;

	value = get_value_at_position(info->map, process->curr_pos, 1);
	ocp = (unsigned char)value[3];
	ft_strdel(&value);
	return (ocp);
}

void	increase_position(t_process *process, int add)
{
	process->pc += add;
	process->curr_pos = process->start_pos + process->pc;
	process->curr_pos = process->curr_pos % MEM_SIZE;
}

/*
** *****************************************************************************
** gets the current opcode and check if it is valid
** *****************************************************************************
*/

void	get_op(t_global *info, t_process *process)
{
	unsigned int	op;
	char			*value;
	unsigned char	ocp;

	ocp = 0;
	value = get_value_at_position(info->map, process->curr_pos, 1);
	op = tab_to_int(value);
	ft_strdel(&value);
	increase_position(process, 1);
	if ((process->cycle_left = get_data_from_op(op, process)) == -1)
	{
		process->visu_pos = process->curr_pos;
		return ;
	}
	process->cycle_left--;
	if (process->curr_op.has_ocp)
		ocp = get_ocp(info, process);
	get_op_param(info, process, ocp);
}
