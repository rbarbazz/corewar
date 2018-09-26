/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 11:26:50 by rbarbazz         ###   ########.fr       */
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

void	look_for_op(t_asm *champ)
{
	int		pos;
//	char	op[6];

	if (skip_non_print(champ) <= 1)
		assign_last_lab(champ);
	pos = champ->i;
	while (champ->sfile && champ->sfile[pos] && ft_isalpha(champ->sfile[pos]))
	{
		if (champ->sfile[pos] == LABEL_CHAR)
			return ;
		pos++;
	}
}