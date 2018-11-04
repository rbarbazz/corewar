/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:01:50 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/15 11:38:58 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	h = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[h] != '\0' && len > h)
	{
		if (needle[0] == haystack[h])
		{
			n = 0;
			while (needle[n] == haystack[n + h] && (n + h) < len)
			{
				if (needle[n + 1] == '\0')
					return ((char*)haystack + h);
				n++;
			}
		}
		h++;
	}
	return (NULL);
}
