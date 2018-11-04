/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:54:22 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/01/05 14:03:59 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *toreverse)
{
	char	swap;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(toreverse) - 1;
	while (index < len)
	{
		swap = toreverse[index];
		toreverse[index] = toreverse[len];
		toreverse[len] = swap;
		len--;
		index++;
	}
	return (toreverse);
}
