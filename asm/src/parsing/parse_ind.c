/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 00:17:42 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 00:02:15 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	convert_ushort(t_asm *champ, unsigned short dec)
{
	char			size[3];
	unsigned int	len;

	len = 2;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	size[len] = 0;
	while (len < 2)
		champ->cor_file[champ->header->prog_size++] = size[len++];
}

static int	get_indirect_value(t_asm *champ)
{
	int		i;
	char	nb[6];

	ft_bzero(nb, 6);
	i = 0;
	while (champ->sfile && champ->sfile[champ->i] &&\
	ft_isdigit(champ->sfile[champ->i]))
	{
		if (i > 5)
			error_overflow();
		nb[i++] = champ->sfile[champ->i];
		move_index();
	}
	if (atoull(nb) > (unsigned long long)USHRT_MAX)
		error_overflow();
 	else if (i < 1)
		error_parse();
	else
	{
		convert_ushort(champ, (unsigned short)atoull(nb));
		return (1);
	}
	return (0);
}

int			check_ind(t_asm *champ, t_op *op, int curr_param)
{
	if (get_indirect_value(champ))
	{
		check_param_type(T_IND, op, curr_param);
		return (1);
	}
	return (0);
}