/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:39:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 09:34:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
}

void		exit_fail(void)
{
	free_asm();
	exit(EXIT_FAILURE);
}
