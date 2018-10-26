/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:09:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/26 18:13:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		callback_about(GtkMenuItem *menuitem, t_gtkinfo *i)
{
	(void)menuitem;
	gtk_dialog_run(GTK_DIALOG(i->w.a));
	gtk_widget_hide(i->w.a);
}
