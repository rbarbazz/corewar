/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:48:58 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 15:57:24 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lfork(t_global *info, t_process *process)
{
	t_process	*new;
	int			param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	new = dup_process(info, process);
	if (info->debug)
		ft_printf("P%5d | lfork %hd (%hd)\n", process->process_nb,\
		process->curr_op.param[0], param0 + process->op_pos);
	info->process_count++;
	new->curr_pos = (param0 + process->op_pos) + process->start_pos;
	new->pc = new->curr_pos - new->start_pos;
	new->visu_pos = new->curr_pos;
}
