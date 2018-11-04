/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:22:11 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/11 17:11:30 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*result;

	if (!s)
		return (NULL);
	if (!(result = ft_strnew(len)))
		return (NULL);
	else
		while (start--)
			s++;
	ft_strncpy(result, s, len);
	result[len] = '\0';
	return (result);
}
