/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:57:36 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 11:48:44 by xperrin          ###   ########.fr       */
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
		ft_printf("Changing color tag prop for p%d\n", pnum);
	g_object_set(i->tag.p[p1],
			TAG_TXTCOL_PROP, &color,
			NULL);
}
