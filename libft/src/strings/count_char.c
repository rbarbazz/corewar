/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:56:58 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/13 17:04:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(const char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}
