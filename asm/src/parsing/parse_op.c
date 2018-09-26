/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 17:04:37 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	t_op	*op;

	if (skip_non_print() > 1)
		return ;
	if (!(op = check_name(champ)))
		return ;
	assign_last_lab(champ);
	ft_printf("op : '%s' nb param : %d opcode : %d nb or address : %d\n", op->name, op->nb_param, op->opcode, op->nb_or_address);
	ft_memdel((void**)&op);
}
