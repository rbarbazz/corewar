/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:29:46 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 16:32:42 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include "vm.h"
# include <gtk/gtk.h>

/*
** Messages
*/
# define PL_FMT "Player %d: %s\nLast Live: %d\nLives in current period: %d\n\n"
# define MSG_PTOOMANY "Error: Too many players"
# define MSG_PMISS "Error: Load a player first"
# define MSG_VMSTP "Error: Stop the VM first!"
# define MSG_WINFMT "And the Winner is %s (P%d)!"

# define DBG_NCURSE_SET "Ncurses visual set"
# define DBG_NCURSE_UNSET "Ncurses visual unset"
# define DBG_VM_SET "VM debug visual set"
# define DBG_VM_UNSET "VM debug visual unset"
# define DBG_GUI_SET "VM debug visual set"
# define DBG_GUI_UNSET "VM debug visual unset"
# define DBG_FMT_COL "Changing color tag prop for p%u\n"
# define DBG_PROC_COL "Changing process color tag prop"

/*
** CSS
*/
# define CSS_MEM_FONT " font: 10px monaco;"
# define CSS_MEM_TXTCOLOR  "color: black;"
# define CSS_MEM_BGCOLOR  "background-color: #000000;"

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
** m:  MAIN_WIN (main window)
** a:  ABOUT_WIN(about window)
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
** mem:  The memory display buffer
** play: The player info buffer
**
** v_*: The matching widgets(GtkTextView)
**
** t_*: The matching buffer's  tag table
*/

typedef struct		s_gtktext
{
	GtkTextBuffer	*mem;
	GtkTextBuffer	*play;
	GtkWidget		*v_mem;
	GtkWidget		*v_play;
	GtkTextTagTable	*t_mem;
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
# define CYCLES "b_cycle"

# define COLOR_P1 "o_color_p1"
# define COLOR_P2 "o_color_p2"
# define COLOR_P3 "o_color_p3"
# define COLOR_P4 "o_color_p4"
# define COLOR_PROC "o_color_proc"

typedef struct		s_gtkctrl
{
	GtkButton		*run;
	GtkButton		*pause;
	GtkSpinner		*spin;
	GtkLabel		*cycles;
	GtkColorButton	*color[4];
	GtkColorButton	*color_proc;
}					t_gtkctrl;

/*
** Text tag color shit
*/

# define TAG_TXTCOL_PROP "foreground-rgba"
# define TAG_PROC_PROP "background-rgba"

typedef	enum		e_pnum
{
	p1,
	p2,
	p3,
	p4
}					t_pnum;

typedef struct		s_gtktags
{
	GtkTextTag		*p[4];
	GtkTextTag		*proc;
}					t_gtktags;

/*
**  ___                 ___       __
** | _ \_ _ ___  __ _  |_ _|_ _  / _|___
** |  _/ '_/ _ \/ _` |  | || ' \|  _/ _ \
** |_| |_| \___/\__, | |___|_||_|_| \___/
**              |___/
*/

/*
** run:   run or stop the VM
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
** vm:              Corewar VM info
** builder:         GtkBuilder object
** gladefilename:   path to corewar.glad
** err:             gtk error object
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
	t_gtktags		tag;
	GtkBuilder		*builder;
	gchar			*gladefilename;
	GError			*err;
	int				debug;
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
gboolean			u_text(t_gtkinfo *i);
/*
** gui_win.c
*/
void				vm_exec_end(int finished, t_gtkinfo *i);
/*
** gui_helpers.c
*/
int					get_map_pnum(t_map *map);
/*
** reset.c
*/
void				reset_info(t_global *info);
void				clear_map(t_map *map);
/*
** popup.c
*/
gboolean			display_popup(char *s);
/*
** rice.c
*/
void				memory_widget_pimp(t_gtkinfo *i);
void				create_tags(t_gtkinfo *i);
/*
** call_misc.c
*/
void				callback_about(GtkMenuItem *menuitem, t_gtkinfo *i);
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
/*
** call_debug.c
*/
void				callback_ncurses(GtkToggleButton *button, t_gtkinfo *i);
void				callback_debug_vm(GtkToggleButton *button, t_gtkinfo *i);
void				callback_debug_gui(GtkToggleButton *button, t_gtkinfo *i);
/*
** call_colors.c
*/
void				callback_colorset_p1(GtkColorButton *widget, t_gtkinfo *i);
void				callback_colorset_proc(GtkColorButton *widget, t_gtkinfo *i);

#endif
