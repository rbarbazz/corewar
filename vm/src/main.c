/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/10 11:08:59 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_global(t_global *info, char *prog_name)
{
	info->prog_name = prog_name;
	info->process_head = NULL;
	info->process_tail = NULL;
	info->process_count = 0;
	info->player = NULL;
	info->player_count = 0;
	info->map = NULL;
	info->clock.cycle = 0;
	info->clock.cycle_to_die = CYCLE_TO_DIE;
	info->clock.current_cycle = 0;
	info->clock.dump = 0;
	info->visual = 0;
	info->dump = 0;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

/*
** *****************************************************************************
** 1 - check the arguments and the inputs from the user
** 2 - create the main structure containing players, process and map
** 3 - start the main loop with play()
** 4 - free memory and exit
** *****************************************************************************
*/

int			main(int argc, char **argv)
{
	t_global	*info;

	info = get_global();
	init_global(info, argv[0]);
	check_args(info, argc, argv);
	create_map(info);
	write_player_in_map(info);
	play(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
