/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:45:37 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/29 14:14:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				callback_ncurses(GtkToggleButton *button, t_gtkinfo *i)
{
	(void)button;
	i->vm->sleep = 0;
	i->vm->visual = (i->vm->visual) ? 0 : 1;
	if (i->debug)
		ft_putendl((i->vm->visual) ? DBG_NCURSE_SET : DBG_NCURSE_UNSET);
}

void				callback_debug_vm(GtkToggleButton *button, t_gtkinfo *i)
{
	(void)button;
	i->vm->debug = (i->vm->debug) ? 0 : 1;
	if (i->debug)
		ft_putendl((i->vm->debug) ? DBG_VM_SET : DBG_VM_UNSET);
}

void				callback_debug_gui(GtkToggleButton *button, t_gtkinfo *i)
{
	(void)button;
	i->debug = (i->debug) ? 0 : 1;
	if (i->debug)
		ft_putendl((i->debug) ? DBG_GUI_SET : DBG_GUI_UNSET);
}
