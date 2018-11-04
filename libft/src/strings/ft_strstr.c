/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:39:20 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/10 19:00:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n;
	int	h;

	h = 0;
	n = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[h])
	{
		if (needle[0] == haystack[h])
		{
			while (needle[n] == haystack[n + h])
			{
				n++;
				if (needle[n] == '\0')
					return ((char*)&haystack[h]);
			}
		}
		h++;
	}
	return (NULL);
}
