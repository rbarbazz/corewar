/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:05:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 18:32:23 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	xxd(char *file, int size, int bline)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%.2hhx", file[i++]);
		if (!(i % bline))
			ft_printf("\n");
		else
			ft_printf(" ");
	}
	ft_printf("\n");
}
