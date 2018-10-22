/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:22:30 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/22 16:52:24 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

/*
** Updates the player infos
** PL_FMT: Player ID, Player Name, Last Live, Nbr of lives in cycle
*/

static void		u_text_players(t_gtkinfo *i)
{
	GtkTextIter	end;
	gchar		*buf;
	t_player	*p;

	p = i->vm->player_head;
	gtk_text_buffer_set_text(i->t.play, "", -1);
	gtk_text_buffer_get_start_iter(i->t.play, &end);
	while (p)
	{
		if (!(buf = g_strdup_printf(PL_FMT, p->pnumber, p->name,
					p->last_live, p->curr_live)))
			exit_corewar(MALLOC_ERROR);
		gtk_text_buffer_insert(i->t.play, &end, buf, -1);
		g_free(buf);
		p = p->next;
	}
}

static void		u_text_map(t_gtkinfo *i)
{
	GtkTextIter	end;
	int			curmap;
	t_map		*map;
	char		*hexa;

	gtk_text_buffer_set_text(i->t.mem, "", -1);
	gtk_text_buffer_get_start_iter(i->t.mem, &end);
	map = i->vm->map;
	curmap = -1;
	while (++curmap < MEM_SIZE)
	{
		if (!(hexa = ft_itoa_u(map->c, 16, 0)))
			exit_corewar(MALLOC_ERROR);
		if (ft_strlen(hexa) == 1)
			gtk_text_buffer_insert(i->t.mem, &end, "0", -1);
		gtk_text_buffer_insert(i->t.mem, &end, hexa, -1);
		if (curmap && !(curmap % 63))
			gtk_text_buffer_insert(i->t.mem, &end, "\n", -1);
		else
			gtk_text_buffer_insert(i->t.mem, &end, " ", -1);
		free(hexa);
		map = map->next;
	}
}

void			u_text(t_gtkinfo *i)
{
	u_text_players(i);
	u_text_map(i);
}
