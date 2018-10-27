/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:39:18 by msamak            #+#    #+#             */
/*   Updated: 2018/10/27 13:32:11 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	aff(t_global *info, t_process *process)
{
	int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (!param0)
		process->carry = 1;
	else
		process->carry = 0;
	if (info->debug)
		ft_printf("P%5d | aff r%d (%d)\n", process->process_nb,\
			process->curr_op.param[0], process->reg[process->curr_op.param[0]\
				- 1]);
	if (!info->visual && !info->debug)
		ft_printf("un process dit : %c\n", param0 % 256);
}
