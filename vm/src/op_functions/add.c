/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:28:53 by msamak            #+#    #+#             */
/*   Updated: 2018/10/27 13:31:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** adds value in p0 with value in p1 and store in p2
** *****************************************************************************
*/

void	add(t_global *info, t_process *process)
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
		ft_printf("P%5d | add r%d + r%d r%d\n", process->process_nb,\
			process->curr_op.param[0], process->curr_op.param[1],\
				process->curr_op.param[2]);
	process->reg[process->curr_op.param[2] - 1] = param0 + param1;
	ft_carry(process, process->reg[process->curr_op.param[2] - 1]);
}
