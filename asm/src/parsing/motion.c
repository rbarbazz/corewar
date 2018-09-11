/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:42:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 16:45:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	skip_non_print(t_asm *champ)
{
	while (champ->sfile && champ->sfile[champ->i] &&\
	!ft_isprint(champ->sfile[champ->i]))
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
}

void	move_index(t_asm *champ)
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