/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:57:36 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 16:11:51 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	callback_colorset(GtkColorButton *widget, t_gtkinfo *i)
{
	GdkRGBA		color;
	t_pnum		pnum;

	gtk_color_chooser_get_rgba((GtkColorChooser*)widget, &color);
	pnum = p1;
	while (pnum <= p4)
	{
		if (widget == i->c.color[pnum])
			break ;
		else if (pnum == p4)
			return ;
		pnum++;
	}
	if (i->debug)
		ft_printf(DBG_FMT_COL, pnum);
	g_object_set(i->tag.p[pnum],
			TAG_TXTCOL_PROP, &color,
			NULL);
}

void	callback_colorset_proc(GtkColorButton *widget, t_gtkinfo *i)
{
	GdkRGBA		color;

	gtk_color_chooser_get_rgba((GtkColorChooser*)widget, &color);
	if (i->debug)
		ft_putendl(DBG_PROC_COL);
	g_object_set(i->tag.proc,
			TAG_PROC_PROP, &color,
			NULL);
}
