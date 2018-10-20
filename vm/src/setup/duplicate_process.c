/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:53:54 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/19 12:04:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	assignate_value(t_process *new, t_process *process)
{
	int reg_size;

	reg_size = REG_NUMBER;
	new->curr_op = process->curr_op;
	ft_memcpy(new->reg, process->reg, reg_size * sizeof(int));
	new->carry = process->carry;
	new->op_pnumber = process->op_pnumber;
	new->start_pos = process->start_pos;
	new->curr_pos = process->curr_pos;
	new->visu_pos = process->visu_pos;
	new->op_pos = process->op_pos;
	new->op_pc = process->op_pc;
	new->cycle_left = process->cycle_left;
	ft_bzero(new->type_param, 3 * sizeof(int));
	new->pc = process->pc;
	new->has_live = process->has_live;
	new->valid_ocp = process->valid_ocp;
}

t_process	*duplicate_process(t_global *info, t_process *process)
{
	t_process *tmp;
	t_process *new;

	tmp = info->process_tail;
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		exit_corewar(MALLOC_ERROR);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	assignate_value(new, process);
	new->process_nb = info->process_tail->process_nb + 1;
	info->process_tail = new;
	return (new);
}
