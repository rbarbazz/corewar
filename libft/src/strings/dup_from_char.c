/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_from_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:49:00 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/06 18:03:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dup_from_char(char *str, char c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	while (str && str[i] && str[i] != c)
		i++;
	if (str && str[i])
		dst = ft_strdup(str + i + 1);
	return (dst);
}
