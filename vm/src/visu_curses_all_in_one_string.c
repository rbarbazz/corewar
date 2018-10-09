/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:54:32 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/09 17:40:07 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define MAX_ARENA_COL
#define MAX_LINE
/*
static void	ft_curses_drawbox(void)
{
	int	i;

	attron(COLOR_PAIR(5 | (1 << 3)));
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
	attroff(COLOR_PAIR(5 | (1 << 3)));
}

static void	ft_curses_cycles(t_global *info)
{
	int		line;
	t_cycle	clock;

	clock = info->clock;
	line = TOP_LINE;
	mvprintw(line++, 2, \
	"Total cycles: %d\n  Current cycle: %d\n  Cycles to die: %d", \
	clock.cycle, clock.current_cycle, clock.cycle_to_die);
}

static int	ft_curses_player(t_global *info)
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
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, 4, \
		"Last live: %d\n    Lives in current period: %d", player->last_live, player->curr_live);
		player = player->next;
		i++;
	}
	return (PLAYER_LINE + (4 * (i - 1)));
}

static void	ft_curses_map(t_global *info)
{
	t_map	*map;
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
static void ft_init_colors(void)
{
	start_color();
	use_default_colors();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(1 | (1 << 3), COLOR_BLACK, COLOR_GREEN);
	init_pair(2 | (1 << 3), COLOR_BLACK, COLOR_BLUE);
	init_pair(3 | (1 << 3), COLOR_BLACK, COLOR_YELLOW);
	init_pair(4 | (1 << 3), COLOR_BLACK, COLOR_MAGENTA);
	init_pair(0 | (1 << 3), COLOR_BLACK, COLOR_WHITE);
}
*/

static int	ft_check_screen_size(void)
{
	if (LINES < TOTAL_LINES || COLS < TOTAL_COLS)
		return (1);
	return (SUCCESS);
}

#define FONT_RESET		"\033[0m "

#define BACK_BLACK		"\033[40m"
#define BACK_WHITE		"\033[47m"
#define BACK_GREEN		"\033[42m"
#define BACK_YELLOW		"\033[43m"
#define BACK_BLUE		"\033[44m"
#define BACK_MAGENTA	"\033[45m"

#define FRONT_BLACK		"\033[30m"
#define FRONT_WHITE		"\033[37m"
#define FRONT_GREEN		"\033[32m"
#define FRONT_YELLOW	"\033[33m"
#define FRONT_BLUE		"\033[34m"
#define FRONT_MAGENTA	"\033[35m"


static void	ft_put_inverted_color(int p, char *new_map)
{
	ft_strcpy(new_map, FRONT_BLACK);
	if (p == 1)
		ft_strcpy(new_map + 5, BACK_BLUE);
	else if (p == 2)
		ft_strcpy(new_map + 5, BACK_GREEN);
	else if (p == 3)
		ft_strcpy(new_map + 5, BACK_YELLOW);
	else if (p == 4)
		ft_strcpy(new_map + 5, BACK_MAGENTA);
	else
		ft_strcpy(new_map + 5, BACK_WHITE);
}

static void	ft_put_normal_color(int p, char *new_map)
{
	ft_strcpy(new_map, BACK_BLACK);
	if (p == 1)
		ft_strcpy(new_map + 5, FRONT_BLUE);
	else if (p == 2)
		ft_strcpy(new_map + 5, FRONT_GREEN);
	else if (p == 3)
		ft_strcpy(new_map + 5, FRONT_YELLOW);
	else if (p == 4)
		ft_strcpy(new_map + 5, FRONT_MAGENTA);
	else
		ft_strcpy(new_map + 5, FRONT_WHITE);
}

int		ft_put_color(int player, int cur, char *new_map)
{
	if (cur)
		ft_put_inverted_color(player, new_map);
	else
		ft_put_normal_color(player, new_map);
	return (10);
}

int		ft_put_hex_and_end_color(char c, char *new_map)
{
	if ((new_map[0] = ((c & 0xF0) >> 4)) < 0x0A)
		new_map[0] = new_map[0] + '0';
	else
		new_map[0] = new_map[0] - 0x0A + 'A';
	if ((new_map[1] = (c & 0x0F)) < 0x0A)
		new_map[1] = new_map[1] + '0';
	else
		new_map[1] = new_map[1] - 0x0A + 'A';
	ft_strcpy(new_map + 2, FONT_RESET);
	return (7);
}

static char	*ft_bufferize_map(t_global *info)
{
	char	*new_map;
	t_map	*map;
	int		i;
	int		pos;

	new_map = ft_strnew(72908);
	i = 0;
	pos = 0;
	map = info->map;
	while (map)
	{
		pos = pos + ft_put_color(map->player, map->current, new_map + pos);
		pos = pos + ft_put_hex_and_end_color(map->c, new_map + pos);
		map = map->next;
		i++;
		if (i == 64 && map)
			;//ajouter un \n et 51 espaces
	}
	return (new_map);
}

int	ft_visu_curses(t_global *info)
{
	static int	first = 1;
	int ret;
	char *map;

	if (first)
	{
		initscr();
//		ft_init_colors();
		if (ft_check_screen_size())
		{
			mvprintw(LINES / 2, COLS / 2, \
					"Your terminal is too small to correctly \
					output using Ncurses.\n\
					Press 'Q' to quit\n\
					Press any other key to launch Corewar without Ncurses view.");
			ret = getch();
			endwin();
			if (ret == 'q')
				return (1);
			else
			{
				info->visual = 0;
				return (SUCCESS);
			}
		}
		first = 0;
	}
	map = ft_bufferize_map(info);
	clear();
	move(TOP_LINE, ARENA_START_COL);
	write(1, map, 69632);
//	ft_curses_cycles(info);
//	ret = ft_curses_player(info);
//	ft_curses_drawbox();
//mvprintw(ret, 2, "Some more ?");
//	ft_curses_map(info);
	refresh();
//	getch();
	return (SUCCESS);
}
