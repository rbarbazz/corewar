/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/06 17:33:44 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	info->process_head = NULL;
	info->process_tail = NULL;
	info->player = NULL;
	info->visual = 0;
	info->map = NULL;
	info->player_count = 0;
	info->process_count = 0;
	info->clock.cycle = 0;
	info->clock.cycle_to_die = CYCLE_TO_DIE;
	info->clock.current_cycle = 0;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

void 		light_map(t_global *info, int position)
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

void 		clean_map(t_global *info)
{
	t_map *map;

	map = info->map;
	while(map)
	{
		map->current = 0;
		map = map->next;
	}
}

void 		update_map(t_global *info)
{
	t_process *tmp_proc;

	tmp_proc = info->process_head;
	clean_map(info);
	while (tmp_proc)
	{
		light_map(info, tmp_proc->position);
		tmp_proc = tmp_proc->next;
	}
}

int			play(t_global *info)
{
	info->process_count = info->player_count;
	create_initial_process(info);
	while (!cycle(info))
	{
		check_process(info);
		update_map(info);
		sleep(bonus(info));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_global	*info;

	info = get_global();
	init_global(info);
	check_args(info, argc, argv);
	create_map(info);
	write_player_in_map(info);
	//Debug
	ft_printf("\033[2J");
	play(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
