/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:49:09 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/29 11:47:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		callback_logic_start(GtkButton *button, t_gtkinfo *i)
{
	if (!i->b.run)
	{
		i->b.run = 1;
		gtk_button_set_label(button, RUN_RUNNING_MSG);
	}
	else
	{
		i->b.run = 0;
		gtk_button_set_label(button, RUN_STOPPED_MSG);
	}
}

void		callback_pause(GtkButton *button, t_gtkinfo *i)
{
	if (!i->b.pause)
	{
		gtk_button_set_label(button, PAUSE_STOPPED_MSG);
		i->b.pause = 1;
	}
	else
	{
		gtk_button_set_label(button, PAUSE_RUNNING_MSG);
		i->b.pause = 0;
	}
}

void		callback_steps(GtkAdjustment *adjustment, t_gtkinfo *i)
{
	gdouble		value;

	value = gtk_adjustment_get_value(adjustment);
	i->b.steps = (int)value;
}

void		callback_speed(GtkAdjustment *adjustment, t_gtkinfo *i)
{
	gdouble		value;

	value = gtk_adjustment_get_value(adjustment);
	i->b.speed = (int)value;
}
