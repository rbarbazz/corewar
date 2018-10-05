/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/05 16:57:21 by rbarbazz         ###   ########.fr       */
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

int			play(t_global *info)
{
	info->process_count = info->player_count;
	create_initial_process(info);
	while (!cycle(info))
	{
		check_process(info);
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
	//ft_printf("\033[2J");
	play(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
