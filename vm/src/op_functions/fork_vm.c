/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:48:58 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 17:21:35 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork_vm(t_global *info, t_process *process)
{
	t_process	*new;
	int			param0;
	short		param0_s;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	param0_s = (short)param0;
	new = dup_process(info, process);
	if (info->debug)
		ft_printf("P%5d | fork %hd (%d)\n", process->process_nb, process->curr_op.param[0], (param0 + process->op_pos) % IDX_MOD);
	param0_s = param0_s % IDX_MOD;
	if (param0_s < 0)
		param0_s = MEM_SIZE + param0_s;
	info->process_count++;
	increase_position(new, param0_s - process->curr_pos + process->op_pos);
	new->visu_pos = new->curr_pos;
}
