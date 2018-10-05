/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:08:04 by msamak            #+#    #+#             */
/*   Updated: 2018/10/05 15:59:17 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	write_one_player(t_map *map, t_player *player, unsigned int i)
{
	if (i < player->prog_size)
	{
		map->c = player->instruction[i];
		map->player = player->player;
		i++;
	}
	return (i);
}

void		write_player_in_map(t_global *info)
{
	t_player		*tmp;
	t_map			*tmp_map;
	unsigned int	i;
	int				j;
	int				position;

	tmp = info->player;
	tmp_map = info->map;
	position = (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	j = 0;
	while (tmp)
	{
		i = 0;
		tmp_map->current = 1;
		tmp->start = j;
		while (j < position)
		{
			i = write_one_player(tmp_map, tmp, i);
			j++;
			tmp_map = tmp_map->next;
		}
		tmp = tmp->next;
		position = position + (ft_sqrt(MEM_SIZE) / info->player_count) \
		* ft_sqrt(MEM_SIZE);
	}
}
