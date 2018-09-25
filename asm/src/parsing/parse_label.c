/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:34:47 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/25 17:51:21 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_label_chars(char c)
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

static void	add_label(t_asm *champ, char *lab_name)
{
	t_lab	*tmp;
	t_lab	*new;

	tmp = champ->lab;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_lab*)ft_memalloc(sizeof(t_lab))))
		exit_fail();
	if (!(ft_strdup(lab_name)))
		exit_fail();
}

static void	get_label(t_asm *champ, int pos)
{
	char	lab_name[pos - champ->i + 1];
	int		i;

	i = 0;
	while (champ->sfile && champ->sfile[champ->i] && champ->sfile[champ->i] != LABEL_CHAR)
	{
		lab_name[i++] = champ->sfile[champ->i];
		move_index(champ);
	}
	lab_name[i] = '\0';
	add_label(champ, lab_name);
	move_index(champ);
	skip_space(champ);
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
		error_parse();
	move_index(champ);
}

/*
** save the current position, then look for a LABEL_CHAR
** if it doesnt find it or get to a non LABEL_CHARS then return
*/

void		look_for_label(t_asm *champ)
{
	int	pos;

	pos = champ->i;
	while (champ->sfile && champ->sfile[pos] &&\
	is_label_chars(champ->sfile[pos]))
		pos++;
	if (champ->sfile && champ->sfile[pos] && champ->sfile[pos] == LABEL_CHAR)
		get_label(champ, pos);
}
