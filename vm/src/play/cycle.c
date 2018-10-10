/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:52:28 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 11:52:08 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** dump option : dumps the memory and exit
** *****************************************************************************
*/

static void	dump_memory(t_global *info)
{
	char	*map;

	map = map_from_list(info);
	xxd(map, MEM_SIZE, 32);
	ft_strdel(&map);
	exit_corewar(SUCCESS);
}

static void	reset_live(t_global *info)
{
	t_player *tmp;

	tmp = info->player;
	while(tmp)
	{
		tmp->curr_live = 0;
		tmp = tmp->next;
	}
}

/*
** *****************************************************************************
** updates the cycle values once every cycle
** *****************************************************************************
*/

int			cycle(t_global *info)
{
	if (info->dump && !info->visual && info->clock.cycle == info->clock.dump)
		dump_memory(info);
	info->clock.cycle++;
	info->clock.current_cycle++;
	if (info->clock.current_cycle == info->clock.cycle_to_die)
	{
		reset_live(info);
		info->clock.cycle_to_die -= CYCLE_DELTA;
		if (info->clock.cycle_to_die < 0)
			info->clock.cycle_to_die = 0;
		info->clock.current_cycle = 0;
	}
	if (info->clock.cycle_to_die <= 0)
		return (1);
	return (0);
}
