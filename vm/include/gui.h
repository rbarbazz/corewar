/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/17 16:46:35 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include "vm.h"
# include <gtk/gtk.h>

# define DIAG_CHAMP "Pick a champion"

/*
**   ___ _____ _  __  ___ _         __  __
**  / __|_   _| |/ / / __| |_ _  _ / _|/ _|
** | (_ | | | | ' <  \__ \  _| || |  _|  _|
**  \___| |_| |_|\_\ |___/\__|\_,_|_| |_|
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

typedef struct		s_gtkwin
{
	GtkWidget		*m;
	GtkWidget		*a;
}					t_gtkwin;

# define MEM_TXT_VIEW "t_mem"
# define PLAY_TXT_VIEW "t_players"

# define BUF_MEM_TXT "buf_mem"
# define BUF_PLAY_TXT "buf_play"

/*
** mem : The memory display buffer
*/

typedef struct		s_gtktext
{
	GtkTextBuffer	*mem;
	GtkTextBuffer	*play;
}					t_gtktext;

/*
**  ___                 ___       __
** | _ \_ _ ___  __ _  |_ _|_ _  / _|___
** |  _/ '_/ _ \/ _` |  | || ' \|  _/ _ \
** |_| |_| \___/\__, | |___|_||_|_| \___/
**              |___/
*/

/*
** run: run or stop the VM;
*/

typedef struct		s_vm_bgl
{
	int				run;
	int				pause;
}					t_vm_bg;

/*
** vm:				Corewar VM info
** builder:			GtkBuilder object
** gladefilename:	path to corewar.glad
** err:				gtk error object
**
** b: background process control
** w: windows widgets
** t: text buffers
*/

typedef struct	s_gtkinfo
{
	t_global	*vm;
	t_vm_bg		b;
	t_gtkwin	w;
	t_gtktext	t;
	GtkBuilder	*builder;
	gchar		*gladefilename;
	GError		*err;
}				t_gtkinfo;

/*
**   ___      _ _ _             _
**  / __|__ _| | | |__  __ _ __| |__ ___
** | (__/ _` | | | '_ \/ _` / _| / /(_-<
**  \___\__,_|_|_|_.__/\__,_\__|_\_\/__/
*/

/*
** bg_loop.c
*/
void			*bg_loop(t_gtkinfo *i);
/*
** gui_main.c
*/
void			callback_test(GtkToggleButton *tbutton, t_gtkinfo *i);
void			about_display(GtkToggleButton *tbutton, t_gtkinfo *i);
/*
** call_filepicker.c
*/
void			callback_player_load(GtkMenuItem *item, t_gtkinfo *i);
/*
** call_logic.c
*/
void			callback_logic_start(GtkWidget *widget, t_gtkinfo *i);
void			callback_dbgvisu(GtkWidget *widget, t_gtkinfo *i);
#endif
