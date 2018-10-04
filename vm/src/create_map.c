/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:17:48 by msamak            #+#    #+#             */
/*   Updated: 2018/10/04 19:41:32 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			init_map(t_global *info, char c)
{
	t_map	*tmp;
	t_map	*new;

	tmp = info->map_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit_corewar(MALLOC_ERROR);
	new->c = c;
	new->player = 0;
	new->current = 0;
	if (!tmp)
		info->map_list = new;
	else
		tmp->next = new;
	return (0);
}

int			get_list_from_map(t_global *info)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		init_map(info, 0);
		i++;
	}
	return (0);
}

int			write_player_in_map(t_global *info)
{
	t_player		*tmp;
	t_map			*tmp_map;
	unsigned int	i;
	int				j;
	int				position;

	tmp = info->player;
	tmp_map = info->map_list;
	position = (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	j = 0;
	while (tmp)
	{
		i = 0;
		while (i < tmp->command_size)
		{
			tmp_map->c = tmp->command[i];
			tmp_map->player = tmp->player;
			i++;
			j++;
			tmp_map = tmp_map->next;
		}
		while (j < position)
		{
			tmp_map = tmp_map->next;
			j++;
		}
		tmp = tmp->next;
		position = position + (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	}
	return (0);
}
