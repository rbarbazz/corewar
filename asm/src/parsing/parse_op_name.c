/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:25:37 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/03 16:53:29 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	match_op(t_op *op)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(g_op_tab[i].name, op->name))
		{
			op->nb_param = g_op_tab[i].nb_param;
			op->opcode = g_op_tab[i].opcode;
			op->has_ocp = g_op_tab[i].has_ocp;
			op->nb_or_address = g_op_tab[i].nb_or_address;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** if find a LABEL_CHAR then return to check with function to parse label
** if no match with any existing op -> ERROR
*/

static int	get_name(t_asm *champ, t_op *op)
{
	int	pos;
	int	i;

	pos = champ->i;
	i = 0;
	while (champ->sfile && champ->sfile[pos] && ft_isalpha(champ->sfile[pos]))
	{
		op->name[i++] = champ->sfile[pos];
		if (champ->sfile[pos] == LABEL_CHAR)
			return (1);
		pos++;
	}
	op->name[i] = '\0';
	if (!match_op(op))
		error_parse();
	while (champ->i < pos)
		move_index();
	return (0);
}

/*
** if name exists and match one of the existing op,
** return the address to the created t_op
*/

int			check_op_name(t_asm *champ)
{
	if (get_name(champ, champ->op))
		return (1);
	champ->cor_file[champ->header->prog_size++] = champ->op->opcode;
	if (champ->header->prog_size > CHAMP_MAX_SIZE)
		error_size();
	champ->curr_op_pos = champ->header->prog_size - 1;
	return (0);
}
