/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/02 15:36:52 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_op(t_asm *champ)
{
	ft_bzero(champ->op->name, 6);
	champ->op->nb_param = 0;
	champ->op->opcode = 0;
	champ->op->has_ocp = 0;
	champ->op->nb_or_address = 0;
}

/*
** in case there is no instruction after a label, remove the last label
*/

static void	remove_last_lab(t_asm *champ)
{
	t_lab	*tmp;

	tmp = champ->lab;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->prev)
			tmp->prev->next = NULL;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

/*
** assign current prog_size to the previous label
*/

static void	assign_last_lab(int pos)
{
	t_lab	*tmp;
	t_asm	*champ;

	champ = get_champ();
	tmp = champ->lab;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp && tmp->pos == -1)
		tmp->pos = pos;
}

/*
** check if next token is an op with its parameters
** if there was a label on the same line of on the previous line,
** change its pos to the current
*/

void		look_for_op(t_asm *champ)
{
	static t_op	op;
	int			pos;

	champ->op = &op;
	init_op(champ);
	pos = champ->header->prog_size;
	if (skip_non_print() > 1)
	{
		remove_last_lab(champ);
		return ;
	}
	if (check_op_name(champ))
		return ;
	check_op_param(champ, champ->op);
	assign_last_lab(pos);
	skip_non_print();
}
