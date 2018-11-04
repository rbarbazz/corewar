/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoinchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:40:25 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 12:40:52 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends a char c at the end of the previously malloced char* s1
*/

char	*strjoinchar(char *s1, char const c)
{
	char	add[2];
	char	*result;

	add[0] = c;
	add[1] = '\0';
	if (!(result = ft_strjoin(s1, add)))
		return (NULL);
	ft_strdel(&s1);
	return (result);
}
