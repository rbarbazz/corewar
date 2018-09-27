/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:09:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 15:21:45 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*static int	check_reg(t_asm *champ, t_op *op, int curr_param)
{
	int		i;
	int		reg;
	char	nb[3];

	ft_bzero(nb, 3);
	i = 0;
	reg = 0;
	if (champ->sfile && champ->sfile[champ->i] && champ->sfile[champ->i] == 'r')
	{
		while (champ->sfile && champ->sfile[champ->i] &&\
		ft_isdigit(champ->sfile[champ->i]) && i < 2)
		{
			nb[i++] = champ->sfile[champ->i];
			move_index();
		}
		if ((reg = ft_atoi(nb)) > REG_NUMBER || reg < 1)
			error_parse();
		else
			add_param(op, reg)

	}
	return (0);
}

void	check_op_param(t_asm *champ, t_op *op)
{
	int curr_param;

	curr_param = 0;
	while (curr_param < op->nb_param)
	{
		skip_space();
		if (!check_reg(champ, champ->op, curr_param))
		{}
		else if //check direct(champ->sfile && champ->sfile[champ->i] == DIRECT_CHAR)
		{}
		else if //check indirect
		{}
		else
		{} //error_parse
		if (curr_param + 1 < op->nb_param)
		{} // check SEPARATOR_CHAR
		curr_param++;
	}
	//check that params match with what is expected(type of params)
	//make ocp if needed and update flag
}*/