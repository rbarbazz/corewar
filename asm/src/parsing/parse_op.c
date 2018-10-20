/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:31:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/19 10:27:35 by rbarbazz         ###   ########.fr       */
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

static int	check_end_of_line(t_asm *champ)
{
	while (champ->sfile && champ->sfile[champ->i]\
		&& champ->sfile[champ->i] != '\n')
	{
		if (ft_isprint(champ->sfile[champ->i]))
			return (1);
		move_index();
	}
	return (0);
}

/*
** *****************************************************************************
** check if next token is an op with its parameters
** if there was a label on the same line of on the previous line,
** change its pos to the current
** *****************************************************************************
*/

void		look_for_op(t_asm *champ)
{
	static t_op	op;
	int			pos;

	champ->op = &op;
	init_op(champ);
	pos = champ->header->prog_size;
	skip_non_print();
	if (!champ->sfile || !champ->sfile[champ->i] || check_op_name(champ))
		return ;
	check_op_param(champ, champ->op);
	if (check_end_of_line(champ))
		error_parse();
	skip_non_print();
}
