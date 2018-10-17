/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/17 15:07:20 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <time.h>

int			play_gtk(t_gtkinfo *i)
{
	i->vm->process_count = i->vm->player_count;
	create_initial_process(i->vm);
	/* if (!i->vm->visual) */
	/* 	display_intro(i->vm); */
	while (!cycle(i->vm) && i->vm->process_count)
	{
		check_process(i->vm);
		update_map(i->vm);
		if (i->vm->visual)
			print_map(i->vm);
		//Debug
		//	usleep(500);
	}
	/* get_winner(i->vm); */
	return (0);
}

static void		u_text_players(t_gtkinfo *i)
{
	int			len;
	GtkTextIter	*end = NULL;
	t_player *p;

	len = ft_strlen(i->vm->player->name);

	gtk_text_buffer_set_text(i->t.play, "Player 1\nName: ", -1);
	gtk_text_buffer_get_end_iter(i->t.play, end);
	gtk_text_buffer_insert(i->t.play, end
			, i->vm->player->name, -1);
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
				write_player_in_map(i->vm);
				gdk_threads_add_idle(u_text_players, i);
				play_gtk(i->vm);
				i->b.run = 0;
			}
			else
				ft_putendl("Not enough players");
		}
		sleep(1);
	}
}
