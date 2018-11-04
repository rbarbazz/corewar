/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:47:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/31 20:35:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dup_to_char(char *str, char c)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (dst = ft_strdup(str));
	if (!(dst = ft_strnew(i + 1)))
		return (NULL);
	j = i;
	i = 0;
	while (i != j)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
