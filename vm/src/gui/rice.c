/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rice.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:11:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 16:28:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		memory_widget_pimp(t_gtkinfo *i)
{
	GtkCssProvider	*provider;
	GtkStyleContext *context;

	provider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(provider,
			"textview {"
			CSS_MEM_FONT
			CSS_MEM_TXTCOLOR
			CSS_MEM_BGCOLOR
			"}",
			-1,
			NULL);
	context = gtk_widget_get_style_context(i->t.v_mem);
	gtk_style_context_add_provider(context,
			GTK_STYLE_PROVIDER(provider),
			GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void		create_tags(t_gtkinfo *i)
{
	t_pnum		pnum;
	GdkRGBA		color;

	pnum = p1;
	while (pnum <= p4)
	{
		i->tag.p[pnum] = gtk_text_tag_new(NULL);
		gtk_color_chooser_get_rgba((GtkColorChooser*)i->c.color[pnum], &color);
		g_object_set(i->tag.p[pnum],
			TAG_TXTCOL_PROP, &color,
			NULL);
		gtk_text_tag_table_add(i->t.t_mem, i->tag.p[pnum]);
		pnum++;
	}
	i->tag.proc = gtk_text_tag_new(NULL);
	gtk_color_chooser_get_rgba((GtkColorChooser*)i->c.color_proc, &color);
	g_object_set(i->tag.proc,
		TAG_PROC_PROP, &color,
		NULL);
	gtk_text_tag_table_add(i->t.t_mem, i->tag.proc);
}
