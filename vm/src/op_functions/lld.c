/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:37:54 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 17:22:15 by msamak           ###   ########.fr       */
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
	if (info->debug)
		ft_printf("P%5d | lld %d r%d\n", process->process_nb, param0,\
		process->curr_op.param[1]);
	process->reg[process->curr_op.param[1] - 1] = param0;
	ft_carry(process, process->reg[process->curr_op.param[1] - 1]);
}
