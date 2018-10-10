/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:29:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 18:31:39 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** iterates on the op tab to find the coresponding opcode
** stores the number of cycles required
** if no match -> return -1
** *****************************************************************************
*/

int		get_data_from_op(int op, t_process *process)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (g_op_tab[i].opcode == op)
		{
			ft_memcpy(process->curr_op.name, g_op_tab[i].name, 6);
			process->curr_op.nb_param = g_op_tab[i].nb_param;
			process->curr_op.opcode = g_op_tab[i].opcode;
			process->curr_op.cycle = g_op_tab[i].cycle;
			process->curr_op.has_ocp = g_op_tab[i].has_ocp;
			process->curr_op.nb_or_address = g_op_tab[i].nb_or_address;
			return (g_op_tab[i].cycle);
		}
		i++;
	}
	return (-1);
}

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
			tmp_proc->visu_pos = tmp_proc->curr_pos;
			//do_op()
		}
		tmp_proc = tmp_proc->prev;
	}
}
