/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/11 18:37:35 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include "vm.h"
# include <gtk/gtk.h>


# define DIAG_CHAMP "Pick a champion"

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
** vm:				Corewar VM info
** builder:			GtkBuilder object
** gladefilename:	path to corewar.glad
** err:				gtk error object
**
** t_gtkwin: windows
*/

typedef struct	s_gtkinfo {
	t_global	*vm;
	GtkBuilder	*builder;
	gchar		*gladefilename;
	GError		*err;
	t_gtkwin	w;
}				t_gtkinfo;

/*
**   ___      _ _ _             _
**  / __|__ _| | | |__  __ _ __| |__ ___
** | (__/ _` | | | '_ \/ _` / _| / /(_-<
**  \___\__,_|_|_|_.__/\__,_\__|_\_\/__/
*/

void			callback_test(GtkToggleButton *tbutton, t_gtkinfo *i);
void			about_display(GtkToggleButton *tbutton, t_gtkinfo *i);

#endif
