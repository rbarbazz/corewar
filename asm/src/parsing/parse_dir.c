/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:13:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 12:24:47 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_direct_value(t_asm *champ)
{
	int		i;
	char	nb[11];

	ft_bzero(nb, 11);
	i = 0;
	while (champ->sfile && champ->sfile[champ->i] &&\
	ft_isdigit(champ->sfile[champ->i]))
	{
		if (i > 10)
			error_overflow();
		nb[i++] = champ->sfile[champ->i];
		move_index();
	}
	if (atoull(nb) > (unsigned long long)UINT_MAX)
		error_overflow();
	else if (i < 1)
		error_parse();
	else
	{
		convert_uint(champ, (unsigned int)atoull(nb));
		return (1);
	}
	return (0);
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
	ft_printf("%s\n", lab_name);
}

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
** check for a label first then a value
*/

int			check_dir(t_asm *champ, t_op *op, int curr_param)
{
	int	ret;

	ret = 0;
	if (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] == DIRECT_CHAR)
	{
		move_index();
		if (!(ret = get_label_pos(champ)))
			ret = get_direct_value(champ);
		if (ret)
		{
			check_param_type(T_DIR, op, curr_param);
			return (1);
		}
		else
			error_parse();
	}
	return (0);
}
