/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:52:28 by msamak            #+#    #+#             */
/*   Updated: 2018/10/17 16:57:48 by msamak           ###   ########.fr       */
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

/*
** *****************************************************************************
** checks if all the processes have lived
** if not kill it
** *****************************************************************************
*/

static void	check_live_process(t_global *info)
{
	t_process	*tmp_proc;
	t_process	*save;

	tmp_proc = info->process_head;
	while (tmp_proc)
	{
		if (tmp_proc->next)
			save = tmp_proc->next;
		else
			save = NULL;
		if (!tmp_proc->has_live)
			kill_process(info, tmp_proc);
		tmp_proc = save;
	}
}

/*
** *****************************************************************************
** resets the live count both for players and processes
** *****************************************************************************
*/

static void	reset_live(t_global *info)
{
	t_player	*tmp;
	t_process	*tmp_proc;

	tmp = info->player_head;
	tmp_proc = info->process_head;
	while (tmp)
	{
		tmp->curr_live = 0;
		tmp = tmp->next;
	}
	while (tmp_proc)
	{
		tmp_proc->has_live = 0;
		tmp_proc = tmp_proc->next;
	}
}

/*
** *****************************************************************************
** updates the cycle values once every cycle
** at each cycle_to_die period :
** 		check if every process has lived
**		resets the live both for player and process
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
		check_live_process(info);
		reset_live(info);
		if (info->clock.curr_live >= NBR_LIVE)
		{
			info->clock.cycle_to_die -= CYCLE_DELTA;
			info->clock.checks = 0;
		}
		else
			info->clock.checks++;
		if (info->clock.checks == MAX_CHECKS)
		{
			info->clock.cycle_to_die -= CYCLE_DELTA;
			info->clock.checks = 0;
		}
		if (info->clock.cycle_to_die < 0)
			info->clock.cycle_to_die = 0;
		info->clock.curr_live = 0;
		info->clock.current_cycle = 0;
	}
	if (info->clock.cycle_to_die <= 0)
		return (1);
	return (0);
}
