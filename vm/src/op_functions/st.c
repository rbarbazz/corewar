/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:32:33 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/12 20:57:40 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** When you get the param1 value it is a T_IND of IND_SIZE (2)
** thus any negative number is based on a ushort
** if you write at an address you need to consider:
** the curr_pos + the address - the curr_op and its params
** *****************************************************************************
*/

void	st(t_global *info, t_process *process)
{
	unsigned int	param0;
	short			param1;

	param0 = 0;
	param1 = process->curr_op.param[1];
	if (get_param_value(info, process, 0, &param0))
		return ;
	param1 %= IDX_MOD;
	if (process->type_param[1] == T_REG)
		process->reg[process->curr_op.param[1] - 1] = param0;
	else
		write_at_position(info->map, process, process->curr_pos + param1 - 5,\
param0);
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
