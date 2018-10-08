/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:04:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 18:35:55 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** turns the map list into a char*
** *****************************************************************************
*/

char	*map_from_list(t_global *info)
{
	t_map	*tmp_m;
	char	*map;
	int		i;

	tmp_m = info->map;
	if (!(map = ft_strnew(4096)))
		exit_corewar(MALLOC_ERROR);
	i = 0;
	while (map && i < MEM_SIZE && tmp_m)
	{
		map[i++] = tmp_m->c;
		tmp_m = tmp_m->next;
	}
	return (map);
}

/*
** *****************************************************************************
** takes a char[3] and returns an int
** *****************************************************************************
*/

int		tab_to_int(char *str)
{
	int res;

	res = 0;
	res = res | str[3];
	res = res | (str[2] << 8);
	res = res | (str[1] << 16);
	res = res | (str[0] << 24);
	return (res);
}
