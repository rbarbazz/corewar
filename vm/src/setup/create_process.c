/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/19 11:58:36 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

static void	assignate_value(t_process *new, t_player *tmp_p)
{
	new->carry = 0;
	new->op_pnumber = 0;
	new->start_pos = tmp_p->start;
	new->curr_pos = tmp_p->start;
	new->visu_pos = tmp_p->start;
	new->op_pos = tmp_p->start;
	new->op_pc = 0;
	new->cycle_left = -1;
	new->pc = 0;
	new->has_live = 0;
	new->valid_ocp = 1;
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
	info->process_tail = new;
	new->prev = tmp;
	if (!tmp)
		info->process_head = new;
	else
		tmp->next = new;
	init_tab(new, tmp_p);
	assignate_value(new, tmp_p);
	new->process_nb = info->process_count + 1;
}

/*
** *****************************************************************************
** creates one process per player at the beginning of the program
** *****************************************************************************
*/

void		create_initial_process(t_global *info)
{
	t_player	*tmp_p;

	tmp_p = info->player_head;
	while (tmp_p)
	{
		add_process(info, tmp_p);
		info->process_count++;
		tmp_p = tmp_p->next;
	}
}
