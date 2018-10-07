/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:54:32 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/07 17:21:29 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_drawbox(void)
{
	int	i;

	attron(COLOR_PAIR(16));
	mvprintw(0, 0, "+");
	mvprintw(0, COLS - 1, "+");
	mvprintw(LINES - 1, 0, "+");
	mvprintw(LINES - 1, COLS - 1, "+");
	i = 0;
	while (++i < COLS - 1)
	{
		mvprintw(0, i, "-");
		mvprintw(LINES - 1, i, "-");
	}
	i = 0;
	while (++i < LINES - 1)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, COLS - 1, "|");
		mvprintw(i, SEP_COL, "|");
	}
}

void	ft_print_info(int cycle, int cycle_to_die, int current_cycle)
{
	int		line;

	line = TOP_LINE;
	mvprintw(line++, INFO_START_COL, \
	"Total cycles: %d", cycle);
	mvprintw(line++, INFO_START_COL, \
	"Current cycle: %d", current_cycle);
	mvprintw(line++, INFO_START_COL, \
	"Cycles to die: %d", cycle_to_die);
}

int	ft_print_player(void)
{
	t_global	*env;
	t_player	*player;
	int		i;

	env = get_global();
	player = env->player;
	i = 1;
	while (player)
	{
		use_default_colors();
		mvprintw(PLAYER_LINE + ((i - 1) * 4), INFO_START_COL, \
		"Player -%d: ", i);
		attron(COLOR_PAIR(player->player));
		printw("%s", player->name);
		attroff(COLOR_PAIR(player->player));
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, INFO_START_COL, \
		"  Last live:");
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 2, INFO_START_COL, \
		"  Lives in current period:");
		player = player->next;
		i++;
	}
	return (PLAYER_LINE + (4 * (i - 1)));
}

void	ft_print_map(void)
{
	t_global	*env;
	t_map		*map;
	int		col;
	int		line;

	env = get_global();
	map = env->map_list;
	line = TOP_LINE;
	col = ARENA_START_COL;
	while (map)
	{
		attron(COLOR_PAIR(map->player | (map->current << 3)));
		mvprintw(line, col, "%02X", 0xFF & map->c);
		attroff(COLOR_PAIR(map->player | (map->current << 3)));
		col = col + 3;
		if (col > (COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
		map = map->next;
	}
}

int	ft_visu(int cycle, int cycle_to_die, int current_cycle)
{
	int ret;

	clear();
	start_color();
	init_pair(16, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(1 | (1 << 3), COLOR_BLACK, COLOR_GREEN);
	init_pair(2 | (1 << 3), COLOR_BLACK, COLOR_BLUE);
	init_pair(3 | (1 << 3), COLOR_BLACK, COLOR_YELLOW);
	init_pair(4 | (1 << 3), COLOR_BLACK, COLOR_MAGENTA);

	ft_drawbox();
	ft_print_info(cycle, cycle_to_die, current_cycle);
	ret = ft_print_player();
mvprintw(ret, 2, "Some more ?");
	ft_print_map();
	refresh();
	getch();
	return (SUCCESS);
}
