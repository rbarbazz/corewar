/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/07 14:56:22 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	info->process = NULL;
	info->player = NULL;
	info->visual = 0;
	info->map_list = NULL;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

int			main(int argc, char **argv)
{
	t_global	*info;
	int cycle;
	int	cycle_to_die;
	int	current_cycle;

	info = get_global();
	check_args(info, argc, argv);
	get_list_from_map(info);
	write_player_in_map(info);
//	ft_printf("\033[2J");
//--------------
initscr();
//--------------
	cycle = 0;
	cycle_to_die = CYCLE_TO_DIE;
	current_cycle = 0;
	while (cycle_to_die > 0)
	{
		//print_map_list(info);
		sleep(1/5);
//		ft_printf("\033[H");
//		ft_printf("Cycle : %d\n", cycle);
//		ft_printf("CYCLE_TO_DIE : %d\n", cycle_to_die);
		cycle++;
		current_cycle++;
		if (current_cycle == cycle_to_die)
		{
			cycle_to_die = cycle_to_die - CYCLE_DELTA;
			current_cycle = 0;
		}
//		ft_printf("\033[0m");
//--------------
ft_visu(cycle, cycle_to_die, current_cycle);
//--------------
	}
getch();
	endwin();
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
