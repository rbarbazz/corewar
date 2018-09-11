/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:39:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 18:32:55 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_asm(void)
{
	t_asm	*champ;

	champ = get_champ();
	if (champ->sfile)
		ft_strdel(&champ->sfile);
}

void		exit_fail(void)
{
	free_asm();
	exit(EXIT_FAILURE);
}
