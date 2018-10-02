/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:17:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/02 15:47:31 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_reg(t_asm *champ, t_op *op, int curr_param)
{
	int		i;
	int		reg;
	char	nb[3];

	ft_bzero(nb, 3);
	i = 0;
	reg = 0;
	if (champ->sfile && champ->sfile[champ->i] && champ->sfile[champ->i] == 'r')
	{
		move_index();
		while (champ->sfile && champ->sfile[champ->i] &&\
		ft_isdigit(champ->sfile[champ->i]) && i < 2)
		{
			nb[i++] = champ->sfile[champ->i];
			move_index();
		}
		if ((reg = ft_atoi(nb)) > REG_NUMBER || reg < 1)
			error_parse();
		else
		{
			champ->cor_file[champ->header->prog_size++] = reg;
			if (champ->header->prog_size > CHAMP_MAX_SIZE)
				error_size();
		}
		check_param_type(T_REG, op, curr_param);
		return (1);
	}
	return (0);
}
