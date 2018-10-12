/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:49:09 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/12 18:27:39 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		callback_logic_start(GtkWidget *widget, t_gtkinfo *i)
{
	if (!i->vm->player_count)
	{
		ft_putstr_fd("Load a player first!\n", 2);
		return ;
	}
	write_player_in_map(i->vm);
	play(i->vm);
}

void		callback_dbgvisu(GtkWidget *widget, t_gtkinfo *i)
{
	i->vm->visual = ~(i->vm->visual);
	ft_putendl((i->vm->visual) ? "Debug visual set." : "Debug visual unset.");
}
