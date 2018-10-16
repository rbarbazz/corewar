/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:48:58 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 13:00:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_process	*dup_process(t_global *info, t_process *process)
{
	t_process *tmp;
	t_process *new;

	tmp = info->process_tail;
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		exit_corewar(MALLOC_ERROR);
	ft_memcpy(new->reg, process->reg, REG_NUMBER * sizeof(int));
	new->pc = process->pc;
	new->carry = process->carry;
	new->start_pos = process->start_pos;
	new->curr_pos = process->curr_pos;
	new->visu_pos = process->visu_pos;
	new->cycle_left = process->cycle_left;
	new->curr_op = process->curr_op;
	new->op_pos = process->op_pos;
	new->valid_ocp = process->valid_ocp;
	ft_bzero(new->type_param, 3 * sizeof(int));
	new->has_live = process->has_live;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	info->process_tail = new;
	return (new);
}

void		fork_vm(t_global *info, t_process *process)
{
	t_process	*new;
	int			param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	param0 %= IDX_MOD;
	if ((param0/IDX_MOD) % 2 == 0)
		param0 = param0 + IDX_MOD + IDX_MOD + IDX_MOD;
	new = dup_process(info, process);
	ft_printf("	fork %d (%d)\n", process->curr_op.param[0], param0);
	info->process_count++;
	increase_position(new, param0);
	new->visu_pos = new->curr_pos;
}
