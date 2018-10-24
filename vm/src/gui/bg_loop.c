/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/24 20:16:55 by xperrin          ###   ########.fr       */
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

	create_initial_process(i->vm);
	if (!i->vm->visual)
		display_intro(i->vm);
	while (!finished && i->b.run)
	{
		if (!i->b.pause)
		{
			if ((!i->b.steps || (i->b.steps && delta_cycles != i->b.steps))
					&& !cycle(i->vm) && i->vm->process_count)
			{
				check_process(i->vm);
				delta_cycles++;
				usleep(i->b.speed);

				// debug
				if (i->vm->visual)
				{
						update_map(i->vm);
						ft_visu_curses(i->vm);
				}
				ft_printf("cycles clock %d delta; %d\n", i->vm->clock.cycle, delta_cycles);
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
	// debug
	if (i->vm->visual)
	{
		update_map(i->vm);
		ft_visu_curses(i->vm);
	}

	get_winner(i->vm); /* TODO: gtk version of that */
	free_process();
	reset_info(i->vm);
	i->b.run = 0;
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
				clear_map(i->vm->map);
				write_player_in_map(i->vm);
				play_gtk(i);
			}
			else
			{
				gdk_threads_add_idle((GSourceFunc)display_popup, MSG_PMISS);
				i->b.run = 0;
			}
		}
		sleep(1);
	}
}
