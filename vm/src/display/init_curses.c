/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:42:52 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/11 17:50:07 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_perma_player(t_global *info)
{
	t_player	*player;
	int		i;

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

static void	ft_init_permanent_parts(t_global *info)
{
	int		line;
	t_cycle	clock;

	ft_curses_drawbox();
	clock = info->clock;
	mvprintw(SPEED_LINE, 2, \
	"Cycles/sec: %d", (1000000 / info->speed));
	line = CYCLE_LINE;
	mvprintw(line++, 2, \
	"Total cycles: %d", clock.cycle);
	mvprintw(line++, 2, \
	"Current cycle: %d", clock.current_cycle);
	mvprintw(line, 2, \
	"Cycles to die: %d", clock.cycle_to_die);
	ft_perma_player(info);
}

static void ft_init_colors(void)
{
	start_color();
	use_default_colors();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(1 | (1 << 3), COLOR_BLACK, COLOR_GREEN);
	init_pair(2 | (1 << 3), COLOR_BLACK, COLOR_CYAN);
	init_pair(3 | (1 << 3), COLOR_BLACK, COLOR_YELLOW);
	init_pair(4 | (1 << 3), COLOR_BLACK, COLOR_MAGENTA);
	init_pair(0 | (1 << 3), COLOR_BLACK, COLOR_WHITE);
}

int			ft_init_curses(t_global *info)
{
	initscr();
	cbreak();
	noecho();
	if (ft_check_screen_size())
	{
		mvprintw(LINES / 2, COLS / 3, \
				"Your terminal is too small to correctly");
		mvprintw((LINES / 2) + 1, COLS / 3, \
				"output using Ncurses.");
		mvprintw((LINES / 2) + 3, COLS / 3, \
				"Press any key to launch Corewar without Ncurses view.");
		getch();
		endwin();
		info->visual = 0;
		return (1);
	}
	//nodelay(stdscr, TRUE);
	curs_set(0);
	ft_init_colors();
	ft_init_permanent_parts(info);
	return (SUCCESS);
}
