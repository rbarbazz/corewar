/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/10 18:26:23 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include <gtk/gtk.h>

/*
** Glade window names
*/
# define MAIN_WIN "main_window"
# define ABOUT_WIN "about_window"

/*
** Necessary objects:
** builder: GtkBuilder object
** gladefilename: path to corewar.glad
** err: Gerror object
**
** Windows:
** w_m:  MAIN_WIN (main window)
** w_a:  ABOUT_WIN(about window)
*/

typedef struct		s_gtkinfo {
	GtkBuilder	*builder;
	gchar		*gladefilename;
	GError		*err;
	GtkWidget	*w_m;
	GtkWidget	*w_a;
}					t_gtkinfo;

#endif
