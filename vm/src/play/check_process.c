/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:29:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/16 20:32:56 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** main function to manage the processes
** *****************************************************************************
*/

void	check_process(t_global *info)
{
	t_process	*tmp_proc;

	tmp_proc = info->process_tail;
	while (tmp_proc)
	{
		if (tmp_proc->cycle_left < 0)
			get_op(info, tmp_proc);
		else if (tmp_proc->cycle_left - 1 > 0)
			tmp_proc->cycle_left--;
		else
		{
			tmp_proc->cycle_left = -1;
			if (tmp_proc->valid_ocp)
				do_op(info, tmp_proc);
			else
			{
				tmp_proc->curr_pos = tmp_proc->op_pos;
				tmp_proc->pc = tmp_proc->op_pc;
				increase_position(tmp_proc, 1);
			}
			tmp_proc->visu_pos = tmp_proc->curr_pos;
		}
		tmp_proc = tmp_proc->prev;
	}
}
