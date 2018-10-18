/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:00:00 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/18 13:22:42 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** gets the last live done
** player who did it wins
** if no one lived last player wins
** *****************************************************************************
*/

static void	get_winner(t_global *info)
{
	t_player		*tmp;
	unsigned int	live;
	t_player		*winner;

	tmp = info->player_tail;
	live = 0;
	winner = 0;
	while (tmp)
	{
		if (live <= tmp->last_live)
		{
			live = tmp->last_live;
			winner = tmp;
		}
		tmp = tmp->prev;
	}
	if (!live)
		winner = info->player_tail;
	if (info->visual)
		ft_exit_curses(winner);
	else
		ft_printf("le joueur %d(%s) a gagne\n", winner->player, winner->name);
}

/*
** *****************************************************************************
** where the game takes place
** until cycle returns 1 or there is no process left the game is on
** *****************************************************************************
*/

int			play(t_global *info)
{
	create_initial_process(info);
	if (!info->visual)
		display_intro(info);
	while (!cycle(info) && info->process_count)
	{
		check_process(info);
		if (info->visual)
		{
			update_map(info);
			usleep(ft_visu_curses(info));
		}
	}
	if (info->visual)
	{
		update_map(info);
		usleep(ft_visu_curses(info));
	}
	get_winner(info);
	return (0);
}
