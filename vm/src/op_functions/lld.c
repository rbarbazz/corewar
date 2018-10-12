/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:37:54 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 17:36:01 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lld(t_global *info, t_process *process)
{
	unsigned int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (check_reg(info, process, 1))
		return ;
	process->reg[process->curr_op.param[1] - 1] = param0;
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}