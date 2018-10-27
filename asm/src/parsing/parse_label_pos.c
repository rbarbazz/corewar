/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:28:34 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/27 13:23:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_label_pos(t_asm *champ, char *lab_name, int size)
{
	t_lab_pos	*tmp;
	t_lab_pos	*new;

	tmp = champ->lab_pos;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_lab_pos*)ft_memalloc(sizeof(t_lab_pos))))
		exit_fail();
	if (!(new->name = ft_strdup(lab_name)))
		exit_fail();
	new->pos = champ->header->prog_size;
	new->size = size;
	new->col = champ->col;
	new->line = champ->line;
	new->op_pos = champ->curr_op_pos;
	if (!champ->lab_pos)
		champ->lab_pos = new;
	else
		tmp->next = new;
}

static void	get_lab_pos_name(t_asm *champ, int size)
{
	char	*lab_name;

	if (!(lab_name = ft_strnew(1)))
		exit_fail();
	while (champ->sfile && champ->sfile[champ->i]\
		&& is_label_chars(champ->sfile[champ->i]))
	{
		if (!(lab_name = strjoinchar(lab_name, champ->sfile[champ->i])))
		{
			ft_strdel(&lab_name);
			exit_fail();
		}
		move_index();
	}
	add_label_pos(champ, lab_name, size);
	ft_strdel(&lab_name);
}

/*
** *****************************************************************************
** look for a label as param and store it
** to be checked once all labels have been found
** also used by check_ind
** *****************************************************************************
*/

int			get_label_pos(t_asm *champ, int size)
{
	if (champ->sfile && champ->sfile[champ->i]\
		&& champ->sfile[champ->i] == LABEL_CHAR)
	{
		move_index();
		get_lab_pos_name(champ, size);
		return (1);
	}
	return (0);
}
