/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:22:30 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/18 16:07:56 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		u_text_players(t_gtkinfo *i)
{
	GtkTextIter	end;
	t_player	*p;

	p = i->vm->player_head;
	gtk_text_buffer_set_text(i->t.play, "", -1);
	while (p)
	{
		gtk_text_buffer_get_start_iter(i->t.play, &end);
		gtk_text_buffer_insert(i->t.play, &end, "Player Name: ", -1);
		gtk_text_buffer_insert(i->t.play, &end, p->name, -1);
		gtk_text_buffer_insert(i->t.play, &end, "\nLast live:  \n\n", -1);
		p = p->next;
	}
}

/* static char	hex_value_to_char(char value) */
/* { */
/* 	if (value <= 9) */
/* 		return (value + '0'); */
/* 	else */
/* 		return (value + 'A'); */
/* } */

/* char		*map_to_buffer(t_map *map) */
/* { */
/* 	char	*buffer; */
/* 	int		size; */
/* 	int		i; */
/* 	int		n; */

/* 	size = (MEM_SIZE * 3) - 1; */
/* 	if (!(buffer = ft_strnew(size))) */
/* 		return (NULL); */
/* 	i = 0; */
/* 	n = 0; */
/* 	while (i < MEM_SIZE) */
/* 	{ */
/* 		buffer[n++] = hex_value_to_char((map->c & 0xF0) >> 4); */
/* 		buffer[n++] = hex_value_to_char(map->c & 0x0F); */
/* 		if (++i == MEM_SIZE) */
/* 			buffer[n] = '\0'; */
/* 		else if (i % 64 == 0) */
/* 			buffer[n++] = '\n'; */
/* 		else */
/* 			buffer[n++] = ' '; */
/* 		map = map->next; */
/* 	} */
/* 	return (buffer); */
/* } */

/* void		u_text_map(t_gtkinfo *i) */
/* { */
/* 	gtk_text_buffer_set_text(i->t.mem, i->b.mem, -1); */
/* } */


void		u_text_map(t_gtkinfo *i)
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
