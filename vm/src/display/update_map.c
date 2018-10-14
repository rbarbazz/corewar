/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:40:51 by msamak            #+#    #+#             */
/*   Updated: 2018/10/12 20:15:39 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	light_map(t_global *info, int position)
{
	t_map *tmp_map;

	tmp_map = info->map;
	while (tmp_map && position)
	{
		position--;
		tmp_map = tmp_map->next;
	}
	tmp_map->current = 1;
}

static void	clean_map(t_global *info)
{
	t_map	*map;
	int		i;

	i = MEM_SIZE;
	map = info->map;
	while (map && i--)
	{
		map->current = 0;
		map = map->next;
	}
}

/*
** *****************************************************************************
** updates the map for the display to show the current process position
** *****************************************************************************
*/

void		update_map(t_global *info)
{
	t_process *tmp_proc;

	tmp_proc = info->process_head;
	clean_map(info);
	while (tmp_proc)
	{
		light_map(info, tmp_proc->visu_pos);
		tmp_proc = tmp_proc->next;
	}
}
