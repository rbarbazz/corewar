/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:13:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 15:17:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	find_direct_value(t_asm *champ, t_op *op)
{
	long res;

	res = get_whole_value(champ);
	if (op->nb_or_address == 1)
		convert_ushort(champ, (unsigned short)res);
	else
		convert_uint(champ, (unsigned int)res);
}

static void	add_label_pos(t_asm *champ, char *lab_name)
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
	new->pos = champ->i;
	new->col = champ->col;
	new->line = champ->line;
	if (!champ->lab_pos)
		champ->lab_pos = new;
	else
		tmp->next = new;
}

static void	get_lab_name(t_asm *champ, int pos)
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
	add_label_pos(champ, lab_name);
}

/*
** *****************************************************************************
** look for a label as param and store it
** to be checked once all labels have been found
** also used by check_ind
** *****************************************************************************
*/

int			get_label_pos(t_asm *champ)
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
		get_lab_name(champ, pos);
		return (1);
	}
	return (0);
}

/*
** *****************************************************************************
** check for a label first then a value
** *****************************************************************************
*/

int			check_dir(t_asm *champ, t_op *op, int curr_param)
{
	if (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] == DIRECT_CHAR)
	{
		move_index();
		if (!get_label_pos(champ))
			find_direct_value(champ, op);
		check_param_type(T_DIR, op, curr_param);
		return (1);
	}
	return (0);
}
