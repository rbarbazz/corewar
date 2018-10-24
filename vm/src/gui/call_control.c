/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:49:09 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/24 17:16:57 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		callback_logic_start(GtkWidget *widget, t_gtkinfo *i)
{
	(void)widget;
	if (!i->b.run)
	{
		i->b.run = 1;
		gtk_button_set_label(i->c.run, RUN_RUNNING_MSG);
	}
	else
	{
		/* TODO stop execution signal or is it done?*/
		i->b.run = 0;
		gtk_button_set_label(i->c.run, RUN_STOPPED_MSG);
	}
}

void		callback_pause(GtkWidget *widget, t_gtkinfo *i)
{
	(void)widget;
	if (!i->b.pause)
	{
		gtk_button_set_label(i->c.pause, PAUSE_STOPPED_MSG);
		i->b.pause = 1;
	}
	else
	{
		gtk_button_set_label(i->c.pause, PAUSE_RUNNING_MSG);
		i->b.pause = 0;
	}
}

void		callback_steps(GtkSpinButton *button, t_gtkinfo *i)
{
	(void)button;
	i->b.steps = gtk_spin_button_get_value_as_int(i->c.steps);
}

void		callback_dbgvisu(GtkWidget *widget, t_gtkinfo *i)
{
	(void)widget;
	i->vm->visual = (i->vm->visual) ? 0 : 1;
	ft_putendl((i->vm->visual) ? "Debug visual set." : "Debug visual unset.");
}
