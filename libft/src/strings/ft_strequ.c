/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:59:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/11 15:04:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	t2 = (unsigned char*)s2;
	t1 = (unsigned char*)s1;
	while (t1[i] != '\0' || t2[i] != '\0')
	{
		if (t1[i] != t2[i])
			return (0);
		i++;
	}
	return (1);
}
