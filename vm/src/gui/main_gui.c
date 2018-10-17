/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:07:02 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/17 15:35:17 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "gui.h"
#include <pthread.h>

void		callback_test(GtkToggleButton *tbutton, t_gtkinfo *i)
{
	ft_putendl(i->vm->prog_name);
}

void		about_display(GtkToggleButton *tbutton, t_gtkinfo *i)
{
	ft_putendl("open about win using builder in data here");
}

/*
** Initialize the background logic thread
*/

static int	thread_logic_init(t_gtkinfo *i)
{
	pthread_t	thread;
	int			tret;

	tret = pthread_create(&thread, NULL, (void*)bg_loop, i);
	if (tret)
	{
		ft_putstr_fd("Error: couldn't create the bg thread\n", 2);
		exit (EXIT_FAILURE);
	}
	return (1);
}

/*
** Initialize the GTK info struct and load the glade file
*/

static int	gui_struct_init(t_gtkinfo *i)
{
	/* Struct init */
	ft_bzero(i, sizeof(t_gtkinfo));
	ft_bzero(&i->b, sizeof(t_gtkwin));
	ft_bzero(&i->w, sizeof(t_gtkwin));
	ft_bzero(&i->t, sizeof(t_gtkwin));

	/* Gtk builder and glade init */
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

	/* signal handling & objects get */
	GtkWidget		*w_mem_txt;
	GtkWidget		*w_play_txt;

	gtk_builder_connect_signals(i->builder, i);
	i->w.m = GTK_WIDGET(gtk_builder_get_object(i->builder, MAIN_WIN));
	i->w.a = GTK_WIDGET(gtk_builder_get_object(i->builder, ABOUT_WIN));

	w_mem_txt = GTK_WIDGET(gtk_builder_get_object(i->builder, MEM_TXT_VIEW));
	w_play_txt = GTK_WIDGET(gtk_builder_get_object(i->builder, PLAY_TXT_VIEW));
	i->t.mem = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w_mem_txt));
	i->t.play = gtk_text_view_get_buffer(GTK_TEXT_VIEW(w_play_txt));

	gtk_widget_show_all(i->w.m);
	return (1);
}

/*
** Initialize GTK and the VM
*/

int			main(int ac, char **av)
{
	t_gtkinfo	i;

	gtk_init(&ac, &av);
	if (!gui_struct_init(&i))
		return (1);
	i.vm = get_global();
	init_global(i.vm, av[0]);
	i.vm->gtk = 1;
	thread_logic_init(&i);
	gtk_main();
	free_all();
	return (0);
}
