/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 15:22:22 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_op(t_asm *champ)
{
	ft_bzero(champ->op->name, 6);
	champ->op->nb_param = 0;
	champ->op->opcode = 0;
	champ->op->has_ocp = 0;
	champ->op->nb_or_address = 0;
}

/*
** assign current prog_size to the previous label
*/

static void	assign_last_lab(t_asm *champ)
{
	t_lab	*tmp;

	tmp = champ->lab;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->pos = champ->header->prog_size;
}

/*
** check if next token is an op with its parameters
** if there was a label on the same line of on the previous line,
** change its pos to the current
*/

void		look_for_op(t_asm *champ)
{
	static t_op	op;

	champ->op = &op;
	init_op(champ);
	if (skip_non_print() > 1)
		return ;
	if (check_op_name(champ))
		return ;
	//check_op_param(champ, champ->op);
	assign_last_lab(champ);
	ft_printf("%s\n", champ->cor_file);
	ft_printf("op : '%s' nb param : %d opcode : %d nb or address : %d\n", champ->op->name, champ->op->nb_param, champ->op->opcode, champ->op->nb_or_address);
}
