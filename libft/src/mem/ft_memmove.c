/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:13:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/10 14:09:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	unsigned char		*csrc;
	unsigned long		i;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	if (cdst < csrc)
	{
		while (len > i)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			cdst[len] = csrc[len];
		}
	}
	return (dst);
}
