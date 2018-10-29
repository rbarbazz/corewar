/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/29 12:34:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <time.h>

/*
** Single VM cycle
*/

static void	vm_cycle(t_gtkinfo *i)
{
	check_process(i->vm);
	i->b.delta++;
	usleep(i->b.speed);
	if (i->vm->visual)
	{
		update_map(i->vm);
		ft_visu_curses(i->vm);
	}
	if (i->debug)
		ft_printf("cycles clock %d delta; %d\n",
				i->vm->clock.cycle, i->b.delta);
}

/*
** VM thread execution loop
*/

void		play_gtk(int finished, t_gtkinfo *i)
{
	create_initial_process(i->vm);
	if (!i->vm->visual)
		display_intro(i->vm);
	while (!finished && i->b.run)
	{
		if (!i->b.pause)
		{
			if ((!i->b.steps || (i->b.steps && i->b.delta != i->b.steps))
					&& !cycle(i->vm) && i->vm->process_count)
				vm_cycle(i);
			else if (i->b.steps && i->b.delta == i->b.steps)
			{
				i->b.pause = 1;
				i->b.delta = 0;
			}
			else
				finished = 1;
		}
		else
		{
			i->b.delta = 0;
			sleep(1);
		}
	}
	vm_exec_end(finished, i);
}

/*
** VM thread wait loop
*/

void		*bg_loop(t_gtkinfo *i)
{
	while (1)
	{
		if (i->b.run)
		{
			if (i->vm->player_count)
			{
				clear_map(i->vm->map);
				write_player_in_map(i->vm);
				play_gtk(0, i);
			}
			else
			{
				i->b.run = 0;
				gdk_threads_add_idle(G_SOURCE_FUNC(display_popup), MSG_PMISS);
			}
		}
		sleep(1);
	}
}
