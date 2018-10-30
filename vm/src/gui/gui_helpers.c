/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:59:41 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/30 17:21:26 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	append_in_mem_buf(char *str, int pnum, t_map *map, t_gtkinfo *i)
{
	GtkTextIter	end;

	gtk_text_buffer_get_end_iter(i->t.mem, &end);
	if (pnum == -1)
	{
		gtk_text_buffer_insert_with_tags(i->t.mem, &end, str, -1,
				(!map->current) ? NULL : i->tag.proc,
				NULL);
	}
	else
	{
		gtk_text_buffer_insert_with_tags(i->t.mem, &end, str, -1,
				i->tag.p[pnum],
				(!map->current) ? NULL : i->tag.proc,
				NULL);
	}
}

int		get_map_pnum(t_map *map)
{
	return (map->pnumber - 1);
}
