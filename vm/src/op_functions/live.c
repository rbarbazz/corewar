/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:27:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/10 12:20:21 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_player *get_player_from_nb(t_global *info, t_process *process)
{
	unsigned int x;
	t_player *tmp;

	tmp = info->player;
	x = process->curr_op.param[0];
	while (tmp)
	{
		if ((unsigned int)tmp->player == x)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

void	live(t_global *info, t_process *process)
{
	t_player *player;

	if (!(player = get_player_from_nb(info, process)))
	{
		ft_dprintf(STDERR_FILENO, "un processus a essaye de faire un live pour \
un joueur inconnu\n");
		return ;
	}
	player->curr_live++;
	player->last_live = info->clock.cycle;
	ft_printf("un processus dit que le joueur %d(%s) est en vie\n", player->player, player->name);
}
