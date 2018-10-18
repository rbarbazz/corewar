/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:20:20 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/18 17:22:28 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** idx mod on the address parsed and not on the result !
** *****************************************************************************
*/

void	ld(t_global *info, t_process *process)
{
	int	param0;

	param0 = 0;
	if ((short)process->curr_op.param[0] < 0 && process->type_param[0] == T_IND)
		process->curr_op.param[0] = (short)process->curr_op.param[0];
	if (process->type_param[0] == T_IND)
		process->curr_op.param[0] %= IDX_MOD;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (check_reg(info, process, 1))
		return ;
	if (info->debug)
		ft_printf("P%5d | ld %d r%d\n", process->process_nb, param0,\
		process->curr_op.param[1]);
	process->reg[process->curr_op.param[1] - 1] = param0;
	ft_carry(process, process->reg[process->curr_op.param[1] - 1]);
}
