/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:42:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/18 10:50:02 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** moves forward on the sfile skipping all non printing char including '\n'
*/

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

/*
** moves forward on the sfile skipping all non printing char except '\n'
*/

void	skip_space(t_asm *champ)
{
	while (champ->sfile && champ->sfile[champ->i] &&\
	!ft_isprint(champ->sfile[champ->i]))
	{
		if (champ->sfile[champ->i] == '\n')
			return ;
		else
		{
			champ->i++;
			champ->col++;
		}
	}
}

/*
** proceeds one char forward in the sfile, incrementing the indexes accordingly
*/

void	move_index(t_asm *champ)
{
	if (champ->sfile[champ->i] && champ->sfile[champ->i] == '\n')
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
