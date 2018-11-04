/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:03:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/10 12:27:43 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	int				i;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	while (n > 0)
	{
		*cdst = *csrc;
		if ((unsigned char)c == *csrc)
			return (dst + i + 1);
		csrc++;
		cdst++;
		n--;
		i++;
	}
	return (NULL);
}
