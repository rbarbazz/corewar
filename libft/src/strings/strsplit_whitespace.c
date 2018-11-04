/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:10:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:28:44 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str)
{
	int wc;
	int i;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == 9 || str[i] == 10)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
			i++;
	}
	return (wc);
}

static char	**copy(char **res, const char *str, int wc)
{
	int i;
	int wn;
	int cn;

	wn = 0;
	i = 0;
	while (wn < wc)
	{
		cn = 0;
		if (!(res[wn] = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str)\
			+ 1))))
			return (NULL);
		while (str[i] == 32 || str[i] == 9 || str[i] == 10)
			i++;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
		{
			res[wn][cn] = str[i];
			i++;
			cn++;
		}
		res[wn][cn] = '\0';
		wn++;
	}
	res[wn] = NULL;
	return (res);
}

char		**strsplit_whitespace(const char *str)
{
	char	**res;
	int		wc;

	if (str)
		wc = count_words(str);
	if (!str || !(res = (char**)ft_memalloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	res = copy(res, str, wc);
	return (res);
}
