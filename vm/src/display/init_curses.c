/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:42:52 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/16 16:24:23 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_init_colors(void)
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
	curs_set(0);
	ft_init_colors();
	ft_init_permanent_parts(info);
	return (SUCCESS);
}
