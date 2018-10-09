/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:04:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 18:49:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** gets from 1 to 4 bytes from a position on the map
** *****************************************************************************
*/

char			*get_value_at_position(t_map *map, int position, int size)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(4)))
		exit_corewar(MALLOC_ERROR);
	while (map && (position + size - 1))
	{
		map = map->next;
		position--;
	}
	i = 3;
	while (map && size)
	{
		ret[i--] = map->c;
		map = map->prev;
		size--;
	}
	return (ret);
}

/*
** *****************************************************************************
** turns the map list into a char*
** *****************************************************************************
*/

char			*map_from_list(t_global *info)
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

unsigned int	tab_to_int(char *str)
{
	unsigned int	res;
	unsigned char	*str_m;

	res = 0;
	str_m = (unsigned char*)str;
	res = res | str_m[3];
	res = res | (str_m[2] << 8);
	res = res | (str_m[1] << 16);
	res = res | (str_m[0] << 24);
	return (res);
}
