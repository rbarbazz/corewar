/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:32:33 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/16 11:09:47 by rbarbazz         ###   ########.fr       */
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
	int		param0;
	short	param1;

	param0 = 0;
	param1 = process->curr_op.param[1];
	if (get_param_value(info, process, 0, &param0))
		return ;
	//param1 %= IDX_MOD;
	ft_printf("	st r%d ->", process->curr_op.param[0]);
	if (process->type_param[1] == T_REG)
	{
		ft_printf(" r%d\n", process->curr_op.param[1]);
		process->reg[process->curr_op.param[1] - 1] = param0;
	}
	else
	{
		ft_printf(" %d\n", param1);
		write_at_position(info->map, process, process->op_pos + param1,\
param0);
	}
	if (!param0)
		process->carry = 1;
	else
		process->carry = 0;
}
