/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:39:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 15:42:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_asm(t_sfile *sfile)
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