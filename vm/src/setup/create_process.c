/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/16 15:59:32 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*dup_process(t_global *info, t_process *process)
{
	t_process *tmp;
	t_process *new;

	tmp = info->process_tail;
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		exit_corewar(MALLOC_ERROR);
	new->prev = tmp;
	new->next = NULL;
	new->curr_op = process->curr_op;
	ft_memcpy(new->reg, process->reg, REG_NUMBER * sizeof(int));
	new->carry = process->carry;
	new->process_nb = info->process_count + 1;
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
	info->process_tail = new;
	tmp->next = new;
	return (new);
}

/*
** *****************************************************************************
** sets all register of the process to 0 except the first one to player number
** *****************************************************************************
*/

static void	init_tab(t_process *new, t_player *player)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
		new->reg[i++] = 0;
	new->reg[0] = player->pnumber;
	i = 0;
	while (i < 3)
		new->type_param[i++] = 0;
}

static void	add_process(t_global *info, t_player *tmp_p)
{
	t_process	*tmp;
	t_process	*new;

	tmp = info->process_head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		exit_corewar(MALLOC_ERROR);
	if (!tmp)
		info->process_head = new;
	else
		tmp->next = new;
	new->prev = tmp;
	init_tab(new, tmp_p);
	new->pc = 0;
	new->carry = 0;
	new->start_pos = tmp_p->start;
	new->cycle_left = -1;
	new->process_nb = info->process_count + 1;
	new->valid_ocp = 1;
	new->has_live = 0;
	new->curr_pos = tmp_p->start;
	new->visu_pos = tmp_p->start;
	new->op_pos = tmp_p->start;
	info->process_tail = new;
}

/*
** *****************************************************************************
** creates one process per player at the beginning of the program
** *****************************************************************************
*/

void		create_initial_process(t_global *info)
{
	t_player	*tmp_p;

	tmp_p = info->player;
	while (tmp_p)
	{
		add_process(info, tmp_p);
		info->process_count++;
		tmp_p = tmp_p->next;
	}
}
