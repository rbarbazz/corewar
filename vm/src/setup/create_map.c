/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:17:48 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 14:04:24 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_map(t_global *info)
{
	t_map	*tmp;
	t_map	*new;

	tmp = info->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit_corewar(MALLOC_ERROR);
	new->prev = tmp;
	if (!tmp)
		info->map = new;
	else
		tmp->next = new;
	new->pnumber = 0;
	new->cycle_written = 0;
	new->c = 0;
	new->current = 0;
}

void		create_map(t_global *info)
{
	int		i;
	t_map	*tmp;

	i = 0;
	while (i < MEM_SIZE)
	{
		init_map(info);
		i++;
	}
	tmp = info->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	info->map->prev = tmp;
	tmp->next = info->map;
}
