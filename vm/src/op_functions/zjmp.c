/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 17:16:12 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** jumps from the opcode
** not from curr_pos which at this moment is after the params
** *****************************************************************************
*/

void	zjmp(t_global *info, t_process *process)
{
	int		param0;
	short	param0_s;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	param0_s = (short)param0;
	if (info->debug)
		ft_printf("P%5d | zjmp %d", process->process_nb, param0_s);
	param0_s = param0_s % IDX_MOD;
	if (param0_s < 0)
		param0_s = MEM_SIZE + param0_s;
	if (process->carry)
	{
		if (info->debug)
			ft_printf(" OK\n");
		increase_position(process, param0_s - process->curr_pos +\
		process->op_pos);
	}
	else
		if (info->debug)
			ft_printf(" FAILED\n");
}
