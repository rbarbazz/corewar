/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:54:32 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/11 17:54:47 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_curses_cycles(t_global *info)
{
	int		line;
	t_cycle	clock;

	clock = info->clock;
	line = CYCLE_LINE;
	mvprintw(line, 2 + 14, "      ");
	mvprintw(line++, 2 + 14, \
	"%d", clock.cycle);
	mvprintw(line, 2 + 15, "      ");
	mvprintw(line++, 2 + 15, \
	"%d", clock.current_cycle);
	mvprintw(line, 2 + 15, "      ");
	mvprintw(line, 2 + 15, \
	"%d", clock.cycle_to_die);
}

static int	ft_curses_player(t_global *info)
{
	t_player	*player;
	int		i;

	player = info->player;
	i = 1;
	while (player)
	{
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, 2, \
		"\tLast live: %d     ", player->last_live);
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 2, 2, \
		"\tLives in current period: %d     ", player->curr_live);
		player = player->next;
		i++;
	}
	return (PLAYER_LINE + (4 * (i - 1)));
}

static void	ft_curses_map(t_global *info)
{
	t_map		*map;
	int		col;
	int		line;

	map = info->map;
	line = 2;
	col = ARENA_START_COL;
	while (map)
	{
		attron(COLOR_PAIR(map->player | (map->current << 3)));
		mvprintw(line, col, "%02X", 0xFF & map->c);
		attroff(COLOR_PAIR(map->player | (map->current << 3)));
		col = col + 3;
		if (col > (TOTAL_COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
		map = map->next;
	}
}

int			ft_visu_curses(t_global *info)
{
	static int	first = 1;
	int			ret;

	if (first)
	{
		if (ft_init_curses(info))
			return (0);//Not a successfull operation, but 0 will avoid the usleep
		first = 0;
		attron(COLOR_PAIR(0 | (1 << 3)));
		mvprintw(TOP_LINE, 2, "PAUSED");
		attroff(COLOR_PAIR(0 | (1 << 3)));
	}
	ft_curses_cycles(info);
	ret = ft_curses_player(info);
	ft_curses_map(info);
//mvprintw(ret, 2, "Some more ?");
	move(MSG_LINE, 4);//Try to find a better way (directly in print functions for example)
	refresh();
	return (info->speed);
}
