/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:42:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/22 12:38:36 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** *****************************************************************************
** moves forward on the sfile skipping all non printing char including '\n'
** returns the number of '\n'
** *****************************************************************************
*/

int		skip_non_print(void)
{
	int		ret;
	t_asm	*champ;

	ret = 0;
	champ = get_champ();
	while (champ->sfile && champ->sfile[champ->i]\
	&& !ft_isprint(champ->sfile[champ->i]))
	{
		if (champ->sfile[champ->i] == '\n')
		{
			champ->i++;
			champ->line++;
			ret++;
			champ->col = 1;
		}
		else
		{
			champ->i++;
			champ->col++;
		}
	}
	return (ret);
}

/*
** *****************************************************************************
** moves forward on the sfile skipping all non printing char except '\n'
** *****************************************************************************
*/

void	skip_space(void)
{
	t_asm	*champ;

	champ = get_champ();
	while (champ->sfile && champ->sfile[champ->i]\
	&& !ft_isprint(champ->sfile[champ->i]))
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
** *****************************************************************************
** proceeds one char forward in the sfile, incrementing the indexes accordingly
** *****************************************************************************
*/

void	move_index(void)
{
	t_asm	*champ;

	champ = get_champ();
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
