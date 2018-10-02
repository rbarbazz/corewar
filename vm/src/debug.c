/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:19:14 by msamak            #+#    #+#             */
/*   Updated: 2018/10/02 19:12:03 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			print_map(t_global *info)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%d", info->map[i]);
		i++;
	}
	return (0);
}

int			print_player(t_global *info)
{
	t_player *tmp;

	tmp = info->player;
	while (tmp)
	{
		ft_printf("%s\n", tmp->name);
		ft_printf("%s\n", tmp->comment);
		ft_printf("%d\n", tmp->command_size);
		tmp = tmp->next;
	}
	return (0);
}
