/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses_permanent_parts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:23:28 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/16 16:24:18 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_perma_player(t_global *info)
{
	t_player	*player;
	int			i;

	player = info->player;
	i = 1;
	while (player)
	{
		mvprintw(PLAYER_LINE + ((i - 1) * 4), 2, \
		"Player -%d: ", i);
		attron(COLOR_PAIR(player->player));
		printw("%s", player->name);
		attroff(COLOR_PAIR(player->player));
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, 2, \
		"\tLast live: %d", player->last_live);
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 2, 2, \
		"\tLives in current period: %d", player->curr_live);
		player = player->next;
		i++;
	}
}

static void	ft_curses_drawbox(void)
{
	int	i;

	attron(COLOR_PAIR(0 | (1 << 3)));
	i = -1;
	while (++i < TOTAL_COLS)
	{
		mvprintw(0, i, " ");
		mvprintw(TOTAL_LINES - 1, i, " ");
	}
	i = -1;
	while (++i < TOTAL_LINES)
	{
		mvprintw(i, 0, " ");
		mvprintw(i, TOTAL_COLS - 1, " ");
		if (i != 0 && i != TOTAL_LINES - 1)
			mvprintw(i, SEP_COL, "|");
	}
	attroff(COLOR_PAIR(0 | (1 << 3)));
}

void	ft_init_permanent_parts(t_global *info)
{
	int		line;
	t_cycle	clock;

	ft_curses_drawbox();
	clock = info->clock;
	mvprintw(SLEEP_LINE, 2, "Slow level (micro s): %d", info->sleep);
	line = CYCLE_LINE;
	mvprintw(line++, 2, "Total cycles: %d", clock.cycle);
	mvprintw(line++, 2, "Current cycle: %d", clock.current_cycle);
	mvprintw(line, 2, "Cycles to die: %d", clock.cycle_to_die);
	ft_perma_player(info);
	ft_print_instructions();
}
