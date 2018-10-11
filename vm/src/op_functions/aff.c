/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:39:18 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 14:37:09 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		aff(t_global *info, t_process *process)
{
	if (!(process->reg[process->curr_op.param[0] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
	ft_printf("un process dit : %c\n", process->reg[process->curr_op.param[0] - 1] % 256);
	ft_printf("un process dit : %u\n", process->reg[process->curr_op.param[0] - 1] % 256);
	if (info)
		return ;
}
