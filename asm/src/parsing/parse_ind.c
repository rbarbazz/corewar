/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 00:17:42 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/22 12:30:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** *****************************************************************************
** get the whole number input as direct or indirect
** cast if bigger than value type and limit to LONG_MAX
** also used by check_dir
** *****************************************************************************
*/

long	get_whole_value(t_asm *champ)
{
	long	res;
	int		i;
	char	nb[21];

	ft_bzero(nb, 21);
	i = 0;
	while (champ->sfile && champ->sfile[champ->i]\
	&& (ft_isdigit(champ->sfile[champ->i])\
	|| (!i && champ->sfile[champ->i] == '-')))
	{
		if (i <= 20)
			nb[i++] = champ->sfile[champ->i];
		move_index();
	}
	if (i < 1)
		error_parse();
	if (i > 20 || atol(nb) > LONG_MAX)
		res = LONG_MAX;
	else
		res = atol(nb);
	return (res);
}

int		check_ind(t_asm *champ, t_op *op, int curr_param)
{
	long res;

	if (!get_label_pos(champ, 2))
	{
		res = get_whole_value(champ);
		convert_ushort(champ, (unsigned short)res);
	}
	else
		convert_ushort(champ, 0);
	check_param_type(T_IND, op, curr_param);
	return (1);
}
