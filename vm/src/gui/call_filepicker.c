/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_filepicker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:43:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/11 19:43:20 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

/*
** Champion file chooser
*/

static int		load_champ(t_global *info, char *filename)
{
	char	*file;
	int		fd;

	fd = open_file(filename);
	file = read_file(fd, filename);
	ft_putendl("Loading player...\n");
	if (check_magic(file))
	{
		ft_strdel(&file);
		close_file(fd);
		exit_corewar(INVALID_MAGIC);
	}
	init_player(info, file);
	print_player(info);
	close_file(fd);
	return (0);
}

void			callback_player(GtkMenuItem *item, t_gtkinfo *i)
{
	GtkWidget				*dialog;
	GtkFileChooserAction	action;
	GtkFileChooser			*chooser;
	char					*filename;
	gint					res;

	(void)item;
	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new(DIAG_CHAMP, NULL, action,
			"Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT,
			NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		filename = gtk_file_chooser_get_filename(chooser);
		load_champ(i->vm, filename);
		g_free(filename);
	}
	gtk_widget_destroy(dialog);
}
