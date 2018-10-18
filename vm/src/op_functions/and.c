/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:09:47 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 11:23:50 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	and_vm(t_global *info, t_process *process)
{
	int		param0;
	int		param1;

	param0 = 0;
	param1 = 0;
	if (process->type_param[0] == T_IND)
		process->curr_op.param[0] %= IDX_MOD;
	if (process->type_param[1] == T_IND)
		process->curr_op.param[1] %= IDX_MOD;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	process->reg[process->curr_op.param[2] - 1] = param0 & param1;
	if (info->debug)
	{
		ft_printf("P%5d | and %hd %hd r%d\n", process->process_nb, param0, param1, process->curr_op.param[2]);
	}
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
