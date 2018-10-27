/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:13:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/27 13:22:52 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** *****************************************************************************
** check for a label first then a value
** *****************************************************************************
*/

int			check_dir(t_asm *champ, t_op *op, int curr_param)
{
	long	res;
	int		size;

	res = 0;
	size = 4;
	if (op->nb_or_address == 1)
		size = 2;
	if (champ->sfile && champ->sfile[champ->i]\
		&& champ->sfile[champ->i] == DIRECT_CHAR)
	{
		move_index();
		if (!get_label_pos(champ, size))
			res = get_whole_value(champ);
		if (op->nb_or_address == 1)
			convert_ushort(champ, (unsigned short)res);
		else
			convert_uint(champ, (unsigned int)res);
		check_param_type(T_DIR, op, curr_param);
		return (1);
	}
	return (0);
}
