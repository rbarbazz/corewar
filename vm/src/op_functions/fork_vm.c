/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:48:58 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 15:59:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		fork_vm(t_global *info, t_process *process)
{
	t_process	*new;
	int			param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	param0 %= IDX_MOD;
	new = dup_process(info, process);
	if (info->debug)
		ft_printf("P	%d |	fork %d (%d)\n", process->process_nb, process->curr_op.param[0], param0 + process->op_pos);
	info->process_count++;
	increase_position(new, param0 - 3);
	new->visu_pos = new->curr_pos;
}
