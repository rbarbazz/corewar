/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:36:23 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/30 11:18:47 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbr_len_u(uintmax_t n, int base)
{
	int		i;

	i = 1;
	while (n >= (size_t)base)
	{
		++i;
		n /= base;
	}
	return (i);
}

char	digit(int nb, int maj)
{
	if (nb < 10)
		return ('0' + nb);
	if (maj)
		return ('A' + nb % 10);
	return ('a' + nb % 10);
}

char	*ft_itoa_u(uintmax_t n, int base, int maj)
{
	char	*res;
	int		size;

	size = nbr_len_u(n, base);
	if (!(res = ft_memalloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = 0;
	while (size-- >= 1)
	{
		res[size] = digit(n % base, maj);
		n /= base;
	}
	return (res);
}

char	*ft_itoa(intmax_t n, int base, int maj)
{
	char	*res;
	char	*tmp;

	if (n < 0)
	{
		tmp = ft_itoa_u(-n, base, maj);
		if (!(res = ft_strjoin("-", tmp)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else
		res = ft_itoa_u(n, base, maj);
	return (res);
}
