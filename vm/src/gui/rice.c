/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rice.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:11:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 00:00:37 by xperrin          ###   ########.fr       */
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

	pnum = p1;
	while (pnum != p4)
	{
		i->tag.p[pnum] = gtk_text_tag_new(NULL);
		pnum++;
	}
	/* g_object_set(i->tag.p[p1], */
	/* 		"foreground-rgba", */
	/* 		NULL) */
}
