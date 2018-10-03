/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:19:14 by msamak            #+#    #+#             */
/*   Updated: 2018/10/03 14:40:01 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			print_map(t_global *info)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", info->map[i]);
		i++;
		if (i % 64 == 0)
			ft_printf("\n");
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
		xxd(tmp->command, tmp->command_size);
		tmp = tmp->next;
	}
	return (0);
}
