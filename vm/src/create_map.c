/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:17:48 by msamak            #+#    #+#             */
/*   Updated: 2018/10/05 14:08:21 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			init_map(t_global *info, char c)
{
	t_map	*tmp;
	t_map	*new;

	tmp = info->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit_corewar(MALLOC_ERROR);
	new->c = c;
	new->player = 0;
	new->current = 0;
	if (!tmp)
		info->map = new;
	else
		tmp->next = new;
	return (0);
}

int			create_map(t_global *info)
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
