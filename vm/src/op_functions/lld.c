/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:37:54 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 19:33:07 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lld(t_global *info, t_process *process)
{
	int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (check_reg(info, process, 1))
		return ;
	if (process->type_param[0] == T_IND)
		param0 = param0 >> 16;
	if (info->debug)
		ft_printf("P	%d |	lld %d r%d\n", process->process_nb, param0, process->curr_op.param[1]);
	process->reg[process->curr_op.param[1] - 1] = param0;
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
