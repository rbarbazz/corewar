/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:37:54 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 13:23:15 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lld(t_global *info, t_process *process)
{
	if (process->type_param[0] == T_IND)
	{

	}
	else if (process->type_param[0] == T_DIR)
		process->reg[process->curr_op.param[1] - 1] = process->curr_op.param[0];
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
	if (info)
		return ;
}
