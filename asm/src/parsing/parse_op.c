/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 13:31:56 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
*/

void		look_for_op(t_asm *champ)
{
	t_op	*op;

	if (skip_non_print(champ) > 1)
		return ;
	if (!(op = check_name(champ)))
	 	return ;
	ft_printf("op : %s\n", op->name);
	assign_last_lab(champ);
	exit(0);
}