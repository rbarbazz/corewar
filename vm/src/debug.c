/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:19:14 by msamak            #+#    #+#             */
/*   Updated: 2018/10/03 17:26:45 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			print_map_list(t_global *info)
{
	t_map	*tmp;
	int		i;

	tmp = info->map_list;
	i = 1;
	while (tmp)
	{
		if (tmp->player == 1)
			ft_printf(RED);
		else if (tmp->player == 2)
			ft_printf(GREEN);
		else if (tmp->player == 3)
			ft_printf(YELLOW);
		else if (tmp->player == 4)
			ft_printf(BOLDCYAN);
		else
			ft_printf("\033[0m");
		ft_printf("%.2hhx ", tmp->c);
		tmp = tmp->next;
		if (i++ % 64 == 0)
			ft_printf("\n");
	}
	ft_printf("\033[0m");
	return (0);
}

int			print_player(t_global *info)
{
	t_player *tmp;

	tmp = info->player;
	while (tmp)
	{
		ft_printf("Player Name : %s\n", tmp->name);
		ft_printf("Player Numero : %d\n", tmp->player);
		ft_printf("Player Comment : %s\n", tmp->comment);
		ft_printf("Player command size : %d\n", tmp->command_size);
		xxd(tmp->command, tmp->command_size);
		tmp = tmp->next;
	}
	return (0);
}
