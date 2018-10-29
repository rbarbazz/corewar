/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:03:33 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/29 15:52:19 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	reset_display(t_global *info)
{
	if (!ft_check_screen_size())
	{
		ft_init_permanent_parts(info);
		ft_curses_map(info);
	}
}

static int	ft_interpret_input_switch_pause(t_global *info, int key)
{
	if ((char)key == KEY_PAUSE)
	{
		nodelay(stdscr, FALSE);
		return (1);
	}
	else if (key == RESIZE_SIGNAL)
		reset_display(info);
	else if ((char)key == KEY_SLEEP_UP)
	{
		if (info->sleep + SLEEP_DELTA < SLEEP_LIM_SUP)
			info->sleep += (info->sleep < SLEEP_DELTA) ?
				SLEEP_DELTA / 10 : SLEEP_DELTA;
	}
	else if ((char)key == KEY_SLEEP_DOWN)
		if (info->sleep - (SLEEP_DELTA / 10) >= SLEEP_LIM_INF)
			info->sleep -= (info->sleep <= SLEEP_DELTA) ?
				SLEEP_DELTA / 10 : SLEEP_DELTA;
	return (0);
}

static void	ft_unpause(void)
{
	cbreak();
	nodelay(stdscr, TRUE);
	attron(COLOR_PAIR(5));
	mvprintw(TOP_LINE, 4, " RUNNING ");
	attroff(COLOR_PAIR(5));
}

void		ft_get_input(t_global *info)
{
	static int	pause = 1;
	int			key;

	if (pause == 1)
	{
		attron(COLOR_PAIR(5));
		mvprintw(TOP_LINE, 4, "  PAUSE  ");
		attroff(COLOR_PAIR(5));
		refresh();
		while ((char)(key = getch()) != KEY_PAUSE && key != KEY_STEP)
			if (key == RESIZE_SIGNAL)
				reset_display(info);
			else if (key == KEY_UP)
				fun_code();
		if ((char)key == KEY_PAUSE)
		{
			pause = 0;
			ft_unpause();
		}
	}
	else
		pause = ft_interpret_input_switch_pause(info, getch());
	flushinp();
}
