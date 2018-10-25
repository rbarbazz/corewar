/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/25 23:34:18 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include "vm.h"
# include <gtk/gtk.h>

# define PL_FMT "Player %d: %s\nLast Live: %d\nLives in current period: %d\n\n"

# define MSG_PTOOMANY "Error: Too many players"
# define MSG_PMISS "Error: Load a player first"
# define MSG_VMSTP "Error: Stop the VM first!"

# define MSG_WINFMT "And the Winner is %s (P%d)!"

/*
**   ___ _____ _  __  ___ _         __  __
**  / __|_   _| |/ / / __| |_ _  _ / _|/ _|
** | (_ | | | | ' <  \__ \  _| || |  _|  _|
**  \___| |_| |_|\_\ |___/\__|\_,_|_| |_|
*/

# define DIAG_CHAMP "Select a champion"

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

# define MEM_TXT_VIEW "t_memory"
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
** controls
*/

# define RUN_CTRL "b_run"
# define RUN_STOPPED_MSG "Run"
# define RUN_RUNNING_MSG "Stop"

# define PAUSE_CTRL "b_pause"
# define PAUSE_STOPPED_MSG "Step"
# define PAUSE_RUNNING_MSG "Pause"

# define SPINNER "b_spinner"

typedef struct		s_gtkctrl
{
	GtkButton		*run;
	GtkButton		*pause;
	GtkSpinner		*spin;
}					t_gtkctrl;

/*
**  ___                 ___       __
** | _ \_ _ ___  __ _  |_ _|_ _  / _|___
** |  _/ '_/ _ \/ _` |  | || ' \|  _/ _ \
** |_| |_| \___/\__, | |___|_||_|_| \___/
**              |___/
*/

/*
** run: run or stop the VM;
** pause: is it paused?
** steps: number of steps to run
** speed: microsecond sleep in VM thread
** delta: current nbr of cycles since last pause
*/

typedef struct		s_vm_bg
{
	int				run;
	int				pause;
	int				steps;
	int				speed;
	int				delta;
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

typedef struct		s_gtkinfo
{
	t_global		*vm;
	t_vm_bg			b;
	t_gtkwin		w;
	t_gtktext		t;
	t_gtkctrl		c;
	GtkBuilder		*builder;
	gchar			*gladefilename;
	GError			*err;
}					t_gtkinfo;

/*
**   ___      _ _ _             _
**  / __|__ _| | | |__  __ _ __| |__ ___
** | (__/ _` | | | '_ \/ _` / _| / /(_-<
**  \___\__,_|_|_|_.__/\__,_\__|_\_\/__/
*/

/*
** main_gui.c
*/
void				gui_exit_wrapper(GtkWidget *widget, t_gtkinfo *i);
/*
** bg_loop.c
*/
void				*bg_loop(t_gtkinfo *i);
/*
** update_info.c
*/
void				u_text(t_gtkinfo *i);
/*
** gui_win.c
*/
void				vm_exec_end(int finished, t_gtkinfo *i)
/*
** reset.c
*/
void				reset_info(t_global *info);
void				clear_map(t_map *map);
/*
** popup.c
*/
int					display_popup(char *s);
/*
** call_filepicker.c
*/
void				callback_player_load(GtkMenuItem *item, t_gtkinfo *i);
void				callback_player_unload(GtkMenuItem *item, t_gtkinfo *i);
/*
** call_logic.c
*/
void				callback_logic_start(GtkButton *button, t_gtkinfo *i);
void				callback_pause(GtkButton *button, t_gtkinfo *i);
void				callback_steps(GtkAdjustment *adjustment, t_gtkinfo *i);
void				callback_speed(GtkAdjustment *adjustment, t_gtkinfo *i);
void				callback_dbgvisu(GtkWidget *widget, t_gtkinfo *i);

#endif
