/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_filepicker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:43:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/23 18:33:45 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

/*
** Champion file chooser
*/

void			callback_player_load(GtkMenuItem *item, t_gtkinfo *i)
{
	GtkWidget				*dialog;
	GtkFileChooserAction	action;
	GtkFileChooser			*chooser;
	char					*filename;
	gint					res;

	(void)item;
	if (!i->b.run)
	{
		action = GTK_FILE_CHOOSER_ACTION_OPEN;
		dialog = gtk_file_chooser_dialog_new(DIAG_CHAMP, NULL, action,
				"Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT,
				NULL);
		res = gtk_dialog_run(GTK_DIALOG(dialog));
		if (res == GTK_RESPONSE_ACCEPT)
		{
			chooser = GTK_FILE_CHOOSER(dialog);
			filename = gtk_file_chooser_get_filename(chooser);
			check_champ(i->vm, filename, 0);
			g_free(filename);
		}
		gtk_widget_destroy(dialog);
	}
	else
		gdk_threads_add_idle((GSourceFunc)display_popup, MSG_VMSTP);
}

/*
**Free up champions
*/

void			callback_player_unload(GtkMenuItem *item, t_gtkinfo *i)
{
	(void)item;
	if (!i->b.run)
	{
		free_player();
		i->vm->player_head = NULL;
		i->vm->player_tail = NULL;
		i->vm->player_count = 0;
	}
	else
		gdk_threads_add_idle((GSourceFunc)display_popup, MSG_VMSTP);
}
