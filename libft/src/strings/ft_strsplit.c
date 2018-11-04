/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:24:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:28:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int wc;
	int i;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wc);
}

static char	**copy(char **res, const char *str, char c, int wc)
{
	int i;
	int wn;
	int cn;

	wn = 0;
	i = 0;
	while (wn < wc)
	{
		cn = 0;
		if (!(res[wn] = (char*)ft_memalloc(sizeof(char)\
			* (ft_strlen(str) + 1))))
			return (NULL);
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
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

char		**ft_strsplit(const char *str, char c)
{
	char	**res;
	int		wc;

	if (str && c)
		wc = count_words(str, c);
	if (!str || !(res = (char**)ft_memalloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	res = copy(res, str, c, wc);
	return (res);
}
