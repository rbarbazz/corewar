/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:11:39 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/19 10:12:15 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mem_rev(char *str, size_t n)
{
	char	swap;
	size_t	index;

	index = 0;
	n--;
	while (index < n)
	{
		swap = str[index];
		str[index] = str[n];
		str[n] = swap;
		n--;
		index++;
	}
	return (str);
}
