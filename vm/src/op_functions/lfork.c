/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:48:58 by msamak            #+#    #+#             */
/*   Updated: 2018/10/12 12:56:25 by rbarbazz         ###   ########.fr       */
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
	ft_memcpy(new->reg, process->reg, REG_NUMBER * sizeof(unsigned int));
	new->pc = process->pc;
	new->carry = process->carry;
	new->start_pos = process->start_pos;
	new->curr_pos = process->curr_pos;
	new->visu_pos = process->visu_pos;
	new->cycle_left = process->cycle_left;
	new->curr_op = process->curr_op;
	new->valid_ocp = process->valid_ocp;
	ft_bzero(new->type_param, 3 * sizeof(unsigned int));
	new->has_live = process->has_live;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	info->process_tail = new;
	return (new);
}

void		lfork(t_global *info, t_process *process)
{
	t_process		*new;
	unsigned int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	new = dup_process(info, process);
	param0 -= process->pc;
	increase_position(new, param0 - 3);
	new->visu_pos = new->curr_pos;
	info->process_count++;
}
