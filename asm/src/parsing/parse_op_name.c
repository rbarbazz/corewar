/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:25:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 14:09:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	match_op(t_asm *champ, t_op *op)
{
	int	i;

	i = 0;
	while (g_op_tab[i])
	{
		if (ft_strequ(g_op_tab[i][0], op->name))
			return (1);
		i++;
	}
	return (0);
}

static int	get_name(t_asm *champ, t_op *op)
{
	int	pos;
	int	i;

	pos = champ->i;
	i = 0;
	while (champ->sfile && champ->sfile[pos] &&\
	champ->sfile[pos] != 9 && champ->sfile[pos] != 32)
	{
		op->name[i++] = champ->sfile[pos];
		if (champ->sfile[pos] == LABEL_CHAR)
			return (1);
		pos++;
	}
	op->name[i] = '\0';
	return (0);
}

t_op	*check_name(t_asm *champ)
{
	t_op	*op;

	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		exit_fail();
	if (get_name(champ, op))
	{
		ft_memdel((void**)&op);
		return (NULL);
	}

	return (op);
}
