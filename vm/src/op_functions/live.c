/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:27:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/16 14:33:53 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_player *get_player_from_nb(t_global *info, int param)
{
	t_player *tmp;

	tmp = info->player;
	while (tmp)
	{
		if (tmp->pnumber == param)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

void			live(t_global *info, t_process *process)
{
	t_player	*player;
	int			param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (info->debug)
		ft_printf("P	%d |	live %d\n", process->process_nb, param0);
	info->clock.curr_live++;
	if (!(player = get_player_from_nb(info, param0)))
	{
		if (!info->visual)
			ft_dprintf(STDERR_FILENO, "un processus a essaye de faire un live \
					pour un joueur inconnu\n");
		return ;
	}
	player->curr_live++;
	player->last_live = info->clock.cycle;
	process->has_live = 1;
	if (!info->visual)
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n", player->player, player->name);
}
