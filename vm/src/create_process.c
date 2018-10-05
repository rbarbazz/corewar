/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_reg(t_process *new)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
		ft_bzero(new->reg[i++], REG_SIZE);
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
	init_reg(new);
	new->pc = 0;
	new->carry = 0;
	new->position = tmp_p->start;
	new->cycle_left = -1;
	info->process_tail = new;
}

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