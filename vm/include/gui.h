/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/10 23:32:27 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include <gtk/gtk.h>

/*
**         _         _
** __ __ _(_)_ _  __| |_____ __ _____
** \ V  V / | ' \/ _` / _ \ V  V (_-<
**  \_/\_/|_|_||_\__,_\___/\_/\_//__/
*/

/*
** Glade window names
*/
# define MAIN_WIN "main_window"
# define ABOUT_WIN "about_window"

/*
** w_m:  MAIN_WIN (main window)
** w_a:  ABOUT_WIN(about window)
*/

typedef struct	s_gtkwin {
	GtkWidget	*m;
	GtkWidget	*a;
}				t_gtkwin;

/*
**  _       __
** (_)_ _  / _|___
** | | ' \|  _/ _ \
** |_|_||_|_| \___/
*/

/*
** builder: GtkBuilder object
** gladefilename: path to corewar.glad
** err: gtk error object
**
** t_gtkwin: windows
*/

typedef struct	s_gtkinfo {
	GtkBuilder	*builder;
	gchar		*gladefilename;
	GError		*err;
	t_gtkwin	w;
}				t_gtkinfo;

void callbacktest(GtkToggleButton *tbutton, gpointer data);
#endif
