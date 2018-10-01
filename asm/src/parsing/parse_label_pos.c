/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:28:34 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 17:29:21 by rbarbazz         ###   ########.fr       */
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
	if (!champ->lab_pos)
		champ->lab_pos = new;
	else
		tmp->next = new;
}

static void	get_lab_name(t_asm *champ, int pos, int size)
{
	char	lab_name[pos - champ->i + 1];
	int		i;

	i = 0;
	ft_bzero(lab_name, pos - champ->i + 1);
	while (champ->sfile && champ->sfile[champ->i] &&\
	is_label_chars(champ->sfile[champ->i]))
	{
		lab_name[i++] = champ->sfile[champ->i];
		move_index();
	}
	lab_name[i] = '\0';
	add_label_pos(champ, lab_name, size);
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
	int	pos;

	pos = champ->i;
	if (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] == LABEL_CHAR)
	{
		move_index();
		while (champ->sfile && champ->sfile[pos] &&\
		is_label_chars(champ->sfile[pos]))
			pos++;
		get_lab_name(champ, pos, size);
		return (1);
	}
	return (0);
}
