/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/17 18:26:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <time.h>

static void		u_text_players(t_gtkinfo *i)
{
	int			len;
	GtkTextIter	end;
	t_player	*p;

	len = ft_strlen(i->vm->player_head->name);

	p = i->vm->player_head;
	gtk_text_buffer_set_text(i->t.play, "", -1);
	while (p)
	{
		gtk_text_buffer_get_start_iter(i->t.play, &end);
		gtk_text_buffer_insert(i->t.play, &end, "Player Name: ", -1);
		gtk_text_buffer_insert(i->t.play, &end, p->name, -1);
		gtk_text_buffer_insert(i->t.play, &end, "\nLast live:  \n\n", -1);
		p = p->next;
	}
}

int			play_gtk(t_gtkinfo *i)
{
	int finished = 0;
	int target_cycles = 1000000;

	create_initial_process(i->vm);
	if (!i->vm->visual)
		display_intro(i->vm);
	while (!finished)
	{
		if (!i->b.pause)
		{
			if (!cycle(i->vm) && i->vm->process_count)
			{
				check_process(i->vm);
				update_map(i->vm);
				gdk_threads_add_idle(u_text_players, i);
				if (i->vm->visual)
					usleep(ft_visu_curses(i->vm));
				ft_printf("cycles clock %d\n", i->vm->clock.cycle);
			}
			else
				finished = 1;
		}
		else
			sleep(1);
	}
	update_map(i->vm);
	if (i->vm->visual)
		usleep(ft_visu_curses(i->vm));
	get_winner(i->vm);
	return (0);
}

void			*bg_loop(t_gtkinfo *i)
{
	while (1)
	{
		if (i->b.run)
		{
			ft_putendl("Yooo Im runnin!");
			if (i->vm->player_count)
			{
				/*
				** Not thread safe !!!!
				** gtk_text_buffer_set_text(i->t.mem, i->vm->player->name, -1);
				*/
				i->b.run = 0;
				write_player_in_map(i->vm);
				play_gtk(i);
			}
			else
			{
				ft_putendl("Not enough players");
			}
		}
		sleep(1);
	}
}
