/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:39:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 18:06:35 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_sfile(t_sfile *sfile)
{
	t_sfile	*tmp;

	while (sfile)
	{
		tmp = sfile;
		sfile = sfile->next;
		ft_strdel(&tmp->line);
		ft_memdel((void**)&tmp);
	}
}

void		free_asm(void)
{
	t_asm	*champ;

	champ = get_champ();
	free_sfile(champ->sfile);
}

void		exit_fail(void)
{
	free_asm();
	exit(EXIT_FAILURE);
}