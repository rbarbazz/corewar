/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:54:32 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/14 18:05:04 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_curses_cycles(t_global *info)
{
	int		line;
	t_cycle	clock;

	clock = info->clock;
	line = CYCLE_LINE;
	mvprintw(SLEEP_LINE, 2 + 22, "%d   ", info->sleep);
	mvprintw(line, 2 + 14, "        ");
	mvprintw(line++, 2 + 14, "%d", clock.cycle);
	mvprintw(line, 2 + 15, "      ");
	mvprintw(line++, 2 + 15, "%d", clock.current_cycle);
	mvprintw(line, 2 + 15, "      ");
	mvprintw(line, 2 + 15, "%d", clock.cycle_to_die);
}

static int	ft_curses_player(t_global *info)
{
	t_player	*player;
	int		i;

	player = info->player;
	i = 1;
	while (player)
	{
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, 2,
		"\tLast live: %d     ", player->last_live);
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 2, 2,
		"\tLives in current period: %d     ", player->curr_live);
		player = player->next;
		i++;
	}
	return (PLAYER_LINE + (4 * (i - 1)));
}

static void	ft_curses_map(t_global *info)
{
	t_map		*map;
	int			col;
	int			line;
	int			i;

	map = info->map;
	line = 2;
	col = ARENA_START_COL;
	i = -1;
	while (++i < MEM_SIZE)
	{
		attron(COLOR_PAIR(map->pnumber | (map->current << 3)));
		mvprintw(line, col, "%02X", 0xFF & map->c);
		attroff(COLOR_PAIR(map->pnumber | (map->current << 3)));
		col = col + 3;
		if (col > (TOTAL_COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
		map = map->next;
	}
}

static void	ft_some_usefull_info(t_global *info, int ret)
{
	static int		update = CYCLE_PER_SEC_UPDATE;
	static clock_t	timing = 0;
	double			res;

	mvprintw(++ret, 2, "Processes = %d", info->process_count);
	if (update)
		update--;
	else
		update = CYCLE_PER_SEC_UPDATE;
	if (timing == 0)
	{
		timing = clock();
		mvprintw((ret = ret + 2), 2, "Cycle/sec = 0");
	}
	else if (update == CYCLE_PER_SEC_UPDATE)
	{
		res = (double)(CYCLE_PER_SEC_UPDATE / ((CYCLE_PER_SEC_UPDATE * info->sleep / 1000000.0) \
					+ ((double)(clock() - timing) / CLOCKS_PER_SEC)));
		mvprintw((ret = ret + 2), 2, "Cycle/sec = %.1F   ", res);
		timing = clock();
	}
}

int			ft_visu_curses(t_global *info)
{
	static int	first = 1;
	int			ret;

	if (first)
	{
		if (ft_init_curses(info))
			return (0);
		first--;
	}
	ft_curses_cycles(info);
	ret = ft_curses_player(info);
	ft_curses_map(info);
	ft_some_usefull_info(info, ret);
	ft_get_input(info);
	refresh();
	return (info->sleep);
}
