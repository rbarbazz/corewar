/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:29:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/18 15:37:38 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	action(t_global *info, t_process *tmp_proc)
{
	get_op(info, tmp_proc);
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

static void	get_op_value(t_global *info, t_process *process)
{
	unsigned int	op;
	char			*value;

	value = get_value_at_position(info->map, process->curr_pos, 1);
	op = tab_to_int(value);
	process->op_pnumber = get_op_pnumber(info, process->curr_pos);
	ft_strdel(&value);
	if ((process->cycle_left = get_data_from_op(op, process)) == -1)
	{
		increase_position(process, 1);
		process->visu_pos = process->curr_pos;
		return ;
	}
	process->cycle_left--;
}

/*
** *****************************************************************************
** main function to manage the processes
** *****************************************************************************
*/

void		check_process(t_global *info)
{
	t_process	*tmp_proc;

	tmp_proc = info->process_tail;
	while (tmp_proc)
	{
		if (tmp_proc->cycle_left < 0)
			get_op_value(info, tmp_proc);
		else if (tmp_proc->cycle_left - 1 > 0)
			tmp_proc->cycle_left--;
		else
			action(info, tmp_proc);
		info->visu_pos[tmp_proc->visu_pos % MEM_SIZE] = 1;
		tmp_proc = tmp_proc->prev;
	}
}
