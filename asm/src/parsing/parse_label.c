/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:34:47 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/02 19:26:33 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_label_chars(char c)
{
	int	i;

	i = 0;
	while (LABEL_CHARS && LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

/*
** *****************************************************************************
** save the new label with the pos -1 by default
** will be flipped to the current prog_size if an op is linked to the label
** *****************************************************************************
*/

static void	add_label(t_asm *champ, char *lab_name)
{
	t_lab	*tmp;
	t_lab	*new;

	tmp = champ->lab;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_lab*)ft_memalloc(sizeof(t_lab))))
		exit_fail();
	if (!(new->name = ft_strdup(lab_name)))
		exit_fail();
	new->pos = -1;
	if (!tmp)
		champ->lab = new;
	else
		tmp->next = new;
	new->prev = tmp;
}

/*
** returns 1 if the label already exists
*/

t_lab		*check_lab_exist(t_asm *champ, char *lab_name)
{
	t_lab *tmp;

	tmp = champ->lab;
	while (tmp)
	{
		if (ft_strequ(lab_name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
** *****************************************************************************
** get the label's name and leave the cursor right after LABEL_CHAR
** if the label already exists take the first value
** *****************************************************************************
*/

static void	get_label(t_asm *champ, int pos)
{
	char	lab_name[pos - champ->i + 1];
	int		i;

	i = 0;
	ft_bzero(lab_name, pos - champ->i + 1);
	while (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] != LABEL_CHAR)
	{
		lab_name[i++] = champ->sfile[champ->i];
		move_index();
	}
	lab_name[i] = '\0';
	if (!check_lab_exist(champ, lab_name))
		add_label(champ, lab_name);
	move_index();
}

/*
** *****************************************************************************
** save the current position, then look for a LABEL_CHAR
** if it doesnt find it or get to a non LABEL_CHARS then return
** *****************************************************************************
*/

void		look_for_label(t_asm *champ)
{
	int	pos;

	skip_non_print();
	pos = champ->i;
	while (champ->sfile && champ->sfile[pos] &&\
	is_label_chars(champ->sfile[pos]))
		pos++;
	if (champ->sfile && champ->sfile[pos] && champ->sfile[pos] == LABEL_CHAR)
		get_label(champ, pos);
}
