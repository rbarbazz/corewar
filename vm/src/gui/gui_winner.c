/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_winner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:22:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/25 20:26:04 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		gui_get_winner(t_global *info)
{
	t_player		*tmp;
	unsigned int	live;
	t_player		*winner;

	tmp = info->player_tail;
	live = 0;
	winner = 0;
	while (tmp)
	{
		if (live <= tmp->last_live)
		{
			live = tmp->last_live;
			winner = tmp;
		}
		tmp = tmp->prev;
	}
	if (!live)
		winner = info->player_tail;
	ft_printf("le joueur %d(%s) a gagne\n", winner->player, winner->name);
}
