/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:57:36 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 00:44:51 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	callback_colorset(GtkColorButton *widget, t_gtkinfo *i)
{
	if (widget == i->c.color_p1)
		ft_putendl("yooO! p1");
	else if (widget == i->c.color_p2)
		ft_putendl("yooO! p2");
	else if (widget == i->c.color_p3)
		ft_putendl("yooO! p3");
	else
		ft_putendl("yooO! p4");
	(void)i;
}
