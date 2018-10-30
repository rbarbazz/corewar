/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:07:02 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 14:43:59 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "gui.h"
#include <pthread.h>
#include <time.h>

/*
** GTK quit callback
*/

void			gui_exit_wrapper(GtkWidget *widget, t_gtkinfo *i)
{
	(void)widget;
	if (!i->b.run)
		gtk_main_quit();
	else
	{
		i->b.run = 0;
		sleep(1);
		gtk_main_quit();
	}
}

/*
** Initialize the background logic thread
*/

static int		thread_logic_init(t_gtkinfo *i)
{
	pthread_t	thread;
	int			tret;

	tret = pthread_create(&thread, NULL, (void*)bg_loop, i);
	if (tret)
	{
		ft_putstr_fd("Error: couldn't create the bg thread\n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/*
** Initialize the GTK info struct and load the glade file
*/

static void		gui_struct_get_objs(t_gtkinfo *i)
{
	i->w.m = GTK_WIDGET(gtk_builder_get_object(i->builder, MAIN_WIN));
	i->w.a = GTK_WIDGET(gtk_builder_get_object(i->builder, ABOUT_WIN));
	i->t.v_mem = GTK_WIDGET(gtk_builder_get_object(i->builder, MEM_TXT_VIEW));
	i->t.v_play = GTK_WIDGET(gtk_builder_get_object(i->builder, PLAY_TXT_VIEW));
	i->t.mem = gtk_text_view_get_buffer(GTK_TEXT_VIEW(i->t.v_mem));
	i->t.t_mem = gtk_text_buffer_get_tag_table(i->t.mem);
	i->t.play = gtk_text_view_get_buffer(GTK_TEXT_VIEW(i->t.v_play));
	i->c.spin = GTK_SPINNER(gtk_builder_get_object(i->builder, SPINNER));
	i->c.cycles = GTK_LABEL(gtk_builder_get_object(i->builder, CYCLES));
	i->c.run = GTK_BUTTON(gtk_builder_get_object(i->builder, RUN_CTRL));
	i->c.pause = GTK_BUTTON(gtk_builder_get_object(i->builder, PAUSE_CTRL));
	i->c.color[p1] = GTK_COLOR_BUTTON(gtk_builder_get_object(i->builder,
				COLOR_P1));
	i->c.color[p2] = GTK_COLOR_BUTTON(gtk_builder_get_object(i->builder,
				COLOR_P2));
	i->c.color[p3] = GTK_COLOR_BUTTON(gtk_builder_get_object(i->builder,
				COLOR_P3));
	i->c.color[p4] = GTK_COLOR_BUTTON(gtk_builder_get_object(i->builder,
				COLOR_P4));
}

static int		gui_struct_init(t_gtkinfo *i)
{
	ft_bzero(i, sizeof(t_gtkinfo));
	ft_bzero(&i->b, sizeof(t_gtkwin));
	ft_bzero(&i->w, sizeof(t_gtkwin));
	ft_bzero(&i->t, sizeof(t_gtkwin));
	i->builder = gtk_builder_new();
	i->gladefilename = g_build_filename("corewar.glade", NULL);
	gtk_builder_add_from_file(i->builder,
			i->gladefilename, &i->err);
	g_free(i->gladefilename);
	if (i->err)
	{
		ft_dprintf(2, "Error: %s\n", i->err->message);
		g_error_free(i->err);
		return (0);
	}
	gtk_builder_connect_signals(i->builder, i);
	gui_struct_get_objs(i);
	memory_widget_pimp(i);
	create_tags(i);
	gtk_widget_show_all(i->w.m);
	return (1);
}

/*
** Initialize GTK,
** Initialize the VM structs,
** Launch the BG VM thread,
** Add the idle GTK info update
*/

int				main(int ac, char **av)
{
	t_gtkinfo	i;

	gtk_init(&ac, &av);
	if (!gui_struct_init(&i))
		return (1);
	i.vm = get_global();
	init_global(i.vm, av[0]);
	i.vm->gtk = 1;
	create_map(i.vm);
	gdk_threads_add_idle(G_SOURCE_FUNC(u_text), &i);
	thread_logic_init(&i);
	gtk_main();
	free_all();
	endwin();
	return (0);
}
