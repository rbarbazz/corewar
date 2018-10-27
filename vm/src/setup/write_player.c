/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:08:04 by msamak            #+#    #+#             */
/*   Updated: 2018/10/27 13:35:42 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	write_one_player(t_map *map, t_player *player, unsigned int i)
{
	if (i < player->prog_size)
	{
		map->pnumber = player->pnumber;
		map->cycle_written = 0;
		map->c = player->instruction[i];
		i++;
	}
	return (i);
}

/*
** *****************************************************************************
** writes the player's instructions into the map
** each at a equal distance from the others
** *****************************************************************************
*/

void		write_player_in_map(t_global *info)
{
	t_player		*tmp;
	t_map			*tmp_map;
	unsigned int	i;
	int				j;
	int				position;

	tmp = info->player_head;
	tmp_map = info->map;
	position = (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	j = 0;
	while (tmp)
	{
		i = 0;
		tmp_map->current = 0;
		tmp->start = j;
		while (j < position)
		{
			i = write_one_player(tmp_map, tmp, i);
			j++;
			tmp_map = tmp_map->next;
		}
		tmp = tmp->next;
		position = position + (ft_sqrt(MEM_SIZE) / info->player_count)\
			* ft_sqrt(MEM_SIZE);
	}
}
