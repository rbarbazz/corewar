/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:22:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/26 11:52:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static gboolean		reset_buttons(t_gtkinfo *i)
{
	gtk_button_set_label(i->c.run, RUN_STOPPED_MSG);
	gtk_button_set_label(i->c.pause, PAUSE_RUNNING_MSG);
	i->b.pause = 0;
	return (G_SOURCE_REMOVE);
}

static gboolean		winner_popup(t_player *winner)
{
	GtkWidget	*dialog;

	dialog = gtk_message_dialog_new(NULL,
			GTK_DIALOG_MODAL,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_CLOSE,
			MSG_WINFMT,
			winner->name,
			winner->player);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return (G_SOURCE_REMOVE);
}

static void			gui_get_winner(t_gtkinfo *i)
{
	t_player		*tmp;
	unsigned int	live;
	t_player		*winner;

	tmp = i->vm->player_tail;
	live = 0;
	winner = 0;
	while (tmp)
	{
		if (live <= tmp->last_live)
		{
			live = tmp->last_live;
			winner = tmp;
		}
		tmp = tmp->prev;
	}
	if (!live)
		winner = i->vm->player_tail;
	gdk_threads_add_idle(G_SOURCE_FUNC(winner_popup), winner);
}

/*
** Executed after the main logic loop
*/

void				vm_exec_end(int finished, t_gtkinfo *i)
{
	if (i->vm->visual)
	{
		update_map(i->vm);
		ft_visu_curses(i->vm);
	}
	gdk_threads_add_idle(G_SOURCE_FUNC(reset_buttons), i);
	if (finished)
		gui_get_winner(i);
	free_process();
	reset_info(i->vm);
	i->b.run = 0;
}

