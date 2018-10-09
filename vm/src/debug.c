/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:19:14 by msamak            #+#    #+#             */
/*   Updated: 2018/10/08 13:32:47 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			print_map(t_global *info)
{
	t_map	*tmp;
	int		i;

	tmp = info->map;
	i = 1;
	ft_printf("\033[H");
	while (tmp)
	{
		if (tmp->player == 1)
			ft_printf(RED);
		else if (tmp->player == 2)
			ft_printf(GREEN);
		else if (tmp->player == 3)
			ft_printf(YELLOW);
		else if (tmp->player == 4)
			ft_printf(CYAN);
		else
			ft_printf(RESET);
		if (tmp->current == 1)
			ft_printf(MAGENTA);
		ft_printf("%.2hhx ", tmp->c);
		tmp = tmp->next;
		if (i++ % 64 == 0)
			ft_printf("\n");
		ft_printf(RESET);
	}
	ft_printf("Cycle : %-20dProcess : %-10d\n", info->clock.cycle,\
	info->process_count);
	ft_printf("Cycle to Die : %-10d\n", info->clock.cycle_to_die);
	ft_printf(RESET);
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
		ft_printf("Player command size : %d\n", tmp->prog_size);
		xxd(tmp->instruction, tmp->prog_size);
		tmp = tmp->next;
	}
	return (0);
}
