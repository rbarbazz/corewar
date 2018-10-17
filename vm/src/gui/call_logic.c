/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:49:09 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/17 18:06:11 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		callback_logic_start(GtkWidget *widget, t_gtkinfo *i)
{
	/* if (!i->vm->player_count) */
	/* { */
	/* 	ft_putstr_fd("Load a player first!\n", 2); */
	/* 	return ; */
	/* } */
	/* write_player_in_map(i->vm); */
	/* play(i->vm); */
	i->b.run = 1;
}

void		callback_pause(GtkWidget *widget, t_gtkinfo *i)
{
	i->b.pause = (i->b.pause) ? 0 : 1;
	ft_putendl((i->b.run) ? "Paused" : "Unpaused");
}

void		callback_dbgvisu(GtkWidget *widget, t_gtkinfo *i)
{
	i->vm->visual = (i->vm->visual) ? 0 : 1;
	ft_putendl((i->vm->visual) ? "Debug visual set." : "Debug visual unset.");
}
