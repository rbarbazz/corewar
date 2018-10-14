/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:31:52 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/14 18:07:52 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "time.h"

void		*bg_loop(t_gtkinfo *i)
{
	while (1)
	{
		if (i->b.run)
		{
			ft_putendl("Yooo Im runnin!");
			if (i->vm->player_count)
			{
				gtk_text_buffer_set_text(i->t.mem, i->vm->player->name, -1);
				write_player_in_map(i->vm);
				play(i->vm);
				i->b.run = 0;
			}
			else
				ft_putendl("Not enough players");
		}
		sleep(1);
	}
}
