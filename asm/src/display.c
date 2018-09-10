/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:18:22 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 15:37:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_sfile(t_sfile *sfile)
{
	t_sfile	*tmp;

	tmp = sfile;
	ft_printf("Dumping annotated program on standard output\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}