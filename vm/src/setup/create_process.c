/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/10 18:01:37 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** sets all register of the process to 0 except the first one to player number
** *****************************************************************************
*/

static void	init_reg(t_process *new, t_player *player)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
		new->reg[i++] = 0;
	new->reg[0] = player->player;
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
	init_reg(new, tmp_p);
	new->pc = 0;
	new->carry = 0;
	new->start_pos = tmp_p->start;
	new->cycle_left = -1;
	new->valid_ocp = 1;
	new->has_live = 0;
	new->curr_pos = tmp_p->start;
	new->visu_pos = tmp_p->start;
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
		tmp_p = tmp_p->next;
	}
}
