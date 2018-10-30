/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:57:36 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 09:27:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	callback_colorset(GtkColorButton *widget, t_gtkinfo *i)
{
	GdkRGBA		color;

	gtk_color_chooser_get_rgba((GtkColorChooser*)widget, &color);
	if (widget == i->c.color_p1)
	{
		g_object_set(i->tag.p[p1],
				"foreground-rgba", &color,
				NULL);
		ft_putendl("yooO! p1");
	}
	else if (widget == i->c.color_p2)
	{
		ft_putendl("yooO! p2");
	}
	else if (widget == i->c.color_p3)
	{
		ft_putendl("yooO! p3");
	}
	else
	{
		ft_putendl("yooO! p4");
	}
	(void)i;
}
