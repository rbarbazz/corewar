/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 00:57:27 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/25 17:10:52 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clean up structures prior to a new VM execution
*/

#include "gui.h"

void	reset_info(t_global *info)
{
	ft_bzero(info->visu_pos, MEM_SIZE);
	info->process_head = NULL;
	info->process_tail = NULL;
	info->clock.cycle = 0;
	info->clock.cycle_to_die = CYCLE_TO_DIE;
	info->clock.current_cycle = 0;
	info->clock.dump = 0;
	info->clock.curr_live = 0;
	info->clock.checks = 0;
	info->process_count = 0;
}

void	clear_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		map->pnumber = 0;
		map->cycle_written = 0;
		map->c = 0;
		map->current = 0;
		map = map->next;
		i++;
	}
}
