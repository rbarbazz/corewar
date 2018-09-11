/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 16:29:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	move_index(t_asm *champ)
{
	if (champ->sfile[champ->i] == '\n')
	{
		champ->i++;
		champ->line++;
		champ->col = 1;
	}
	else
	{
		champ->i++;
		champ->col++;
	}
}

static int	get_name(t_asm *champ)
{
	while (champ->sfile && champ->sfile[champ->i] && ft_isprint( champ->sfile[champ->i]))
	{

		move_index(champ);
	}
	while (champ->sfile && champ->sfile[champ->i])
	{

	}
	return (0);
}

int	parser(t_asm *champ)
{
	if (get_name(champ))
	{
		display_error_parse();
		return (1);
	}
	return (0);
}