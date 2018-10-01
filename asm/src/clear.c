/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:39:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 17:01:09 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_lab_pos(t_lab_pos *lab_pos)
{
	t_lab_pos	*tmp;

	while (lab_pos)
	{
		tmp = lab_pos;
		lab_pos = lab_pos->next;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

void		free_lab(t_lab *lab)
{
	t_lab	*tmp;

	while (lab)
	{
		tmp = lab;
		lab = lab->next;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

void		free_asm(void)
{
	t_asm	*champ;

	champ = get_champ();
	if (champ->sfile)
		ft_strdel(&champ->sfile);
	if (champ->lab)
		free_lab(champ->lab);
	if (champ->lab_pos)
		free_lab_pos(champ->lab_pos);
}

void		exit_fail(void)
{
	free_asm();
	exit(EXIT_FAILURE);
}
