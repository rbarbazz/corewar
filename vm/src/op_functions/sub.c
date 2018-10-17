/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:29:00 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 14:05:00 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** subs value in p0 by value in p1 and store in p2
** *****************************************************************************
*/

void		sub(t_global *info, t_process *process)
{
	int	param0;
	int	param1;

	param0 = 0;
	param1 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	if (info->debug)
		ft_printf("P	%d |	sub r%d - r%d -> r%d\n", process->process_nb, process->curr_op.param[0], process->curr_op.param[1], process->curr_op.param[2]);
	process->reg[process->curr_op.param[2] - 1] = param0 - param1;
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
