/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:13:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/29 17:41:55 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	convert_uint(t_asm *champ, unsigned int dec)
{
	char			size[5];
	unsigned int	len;

	len = 4;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	size[len] = 0;
	while (len < 4)
		champ->cor_file[champ->header->prog_size++] = size[len++];
}

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

int			check_dir(t_asm *champ, t_op *op, int curr_param)
{
	if (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] == DIRECT_CHAR)
	{
		move_index();
		if (get_direct_value(champ))
		{
			check_param_type(T_DIR, op, curr_param);
			return (1);
		}
	}
	return (0);
}
