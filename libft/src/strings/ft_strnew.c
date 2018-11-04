/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:13:20 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/30 11:04:19 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (!size || !(mem = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(mem, 0, size);
	mem[size] = '\0';
	return (mem);
}
