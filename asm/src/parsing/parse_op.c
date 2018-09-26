/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 12:29:46 by rbarbazz         ###   ########.fr       */
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

static t_op	*check_name(t_asm *champ)
{
	t_op	*op;

	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		exit_fail();
	if (get_name(champ, op))
	{
		ft_memdel((void**)&op);
		return (NULL);
	}
	ft_printf("op : %s\n", op->name);
	return (op);
}

/*
** check if next token is an op with its parameters
*/

void		look_for_op(t_asm *champ)
{
	t_op	*op;
	int		nb_lines;

	nb_lines = skip_non_print(champ);
	if (!(op = check_name(champ)))
	 	return ;
	if (nb_lines <= 1)
		assign_last_lab(champ);

	exit(0);
}