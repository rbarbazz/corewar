/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_winner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:22:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/25 20:57:58 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static	int		winner_popup(t_player *winner)
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
	return (FALSE);
}

void			gui_get_winner(t_gtkinfo *i)
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
	gdk_threads_add_idle((GSourceFunc)winner_popup, winner);
}
