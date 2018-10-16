/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_playerid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:30:36 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/16 18:50:36 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_p_id(t_global *info, int pnum)
{
	t_player	*players;

	players = info->player_head;
	while (players)
	{
		if (players->pnumber == pnum)
			return (players->player);
		players = players->next;
	}
	return (0);
}
