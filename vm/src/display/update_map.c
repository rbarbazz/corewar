/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:40:51 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 14:47:48 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** updates the map for the display to show the current process position
** *****************************************************************************
*/

void		update_map(t_global *info)
{
	t_map	*map;
	int		i;

	i = 0;
	map = info->map;
	while (map && i < MEM_SIZE)
	{
		if (info->visu_pos[i])
			map->current = 1;
		else
			map->current = 0;
		map = map->next;
		i++;
	}
	ft_bzero(info->visu_pos, MEM_SIZE);
}
