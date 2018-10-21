/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/22 01:01:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <time.h>


/*
** VM thread execution loop
*/

void		play_gtk(t_gtkinfo *i)
{
	int		finished = 0;
	int		delta_cycles = 0;
	int		pause_already = 0;

	create_initial_process(i->vm);
	if (!i->vm->visual)
		display_intro(i->vm);
	while (!finished)
	{
		if (!i->b.pause)
		{
			if ((!i->b.steps || (i->b.steps && delta_cycles != i->b.steps))
					&& !cycle(i->vm) && i->vm->process_count)
			{
				check_process(i->vm);
				update_map(i->vm);

				/* if (!(i->b.mem = map_to_buffer(i->vm->map))) */
				/* 	exit_corewar(MALLOC_ERROR); */
				/* gdk_threads_add_idle(u_text_map, i); */

				ft_printf("cycles clock %d delta; %d\n", i->vm->clock.cycle, delta_cycles);
				delta_cycles++;
			}
			else if (i->b.steps && delta_cycles == i->b.steps)
			{
				i->b.pause = 1;
				delta_cycles = 0;
			}
			else
				finished = 1;
		}
		else
			sleep (1);
	}
	get_winner(i->vm); /* TODO: gtk version of that */
	reset_vm(i->vm);
}

/*
** VM thread wait loop
*/

void			*bg_loop(t_gtkinfo *i)
{
	while (1)
	{
		if (i->b.run)
		{
			if (i->vm->player_count)
			{
				i->b.run = 0;
				// debug
					/* i->b.steps = 1; */
				write_player_in_map(i->vm);
				gdk_threads_add_idle(u_text_map, i);
				play_gtk(i);
			}
			else
			{
				ft_putendl("Not enough players");
				i->b.run = 0;
			}
		}
		sleep(1);
	}
}
