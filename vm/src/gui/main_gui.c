/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gui.c                                         :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:07:02 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/10 23:21:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "gui.h"


void		callback_test(GtkToggleButton *tbutton, gpointer data)
{
	ft_putendl("it works!");
}

/*
** Initialize the GTK info struct and load the glade file
*/

static int	builder_and_glad_init(t_gtkinfo *i)
{
	ft_bzero(i, sizeof(t_gtkinfo));
	ft_bzero(&i->w, sizeof(t_gtkwin));
	i->builder = gtk_builder_new();
	i->gladefilename = g_build_filename("corewar.glade", NULL);
	gtk_builder_add_from_file(i->builder,
			i->gladefilename, &i->err);
	g_free(i->gladefilename);
	if (i->err)
	{
		ft_putstr_fd("Error: Problem loading gladle file\n", 2);
		g_error_free(i->err);
		return (0);
	}
	else
		return (1);
}

/*
** Initialize GTK and the VM structs
*/

int			main(int ac, char **av)
{
	t_gtkinfo		i;

	gtk_init(&ac, &av);
	if (!builder_and_glad_init(&i))
		return (1);
	gtk_builder_connect_signals(i.builder, NULL);
	i.w.m = GTK_WIDGET(gtk_builder_get_object(i.builder, MAIN_WIN));
	i.w.a = GTK_WIDGET(gtk_builder_get_object(i.builder, ABOUT_WIN));
	gtk_widget_show_all(i.w.m);
	gtk_main();
	return (0);
	free_all();
}
