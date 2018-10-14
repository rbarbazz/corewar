/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:03:33 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/13 19:08:37 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_interpret_input_switch_pause(t_global *info, int key)
{
	if ((char)key == KEY_PAUSE)
	{
		nodelay(stdscr, FALSE);
		return (1);

	}
	else if ((char)key == KEY_SLEEP_UP)
	{
		if (info->sleep + SLEEP_DELTA < SLEEP_LIM_SUP)
			info->sleep += SLEEP_DELTA;
	}
	else if ((char)key == KEY_SLEEP_DOWN)
		if (info->sleep - SLEEP_DELTA >= SLEEP_LIM_INF)
			info->sleep -= SLEEP_DELTA;
	return (0);
}

void		ft_get_input(t_global *info)
{
	static int	pause = 1;
	int			key;

	if (pause == 1)
	{
		attron(COLOR_PAIR(0 | (1 << 3)));
		mvprintw(TOP_LINE, 4, "  PAUSE  ");
		refresh();
		while ((char)(key = getch()) != KEY_PAUSE && key != KEY_STEP)
			;
		if (key == KEY_PAUSE)
		{
			pause = 0;
			cbreak();
			nodelay(stdscr, TRUE);
			mvprintw(TOP_LINE, 4, " RUNNING ");
		}
		attroff(COLOR_PAIR(0 | (1 << 3)));
	}
	else
		pause = ft_interpret_input_switch_pause(info, getch());
	flushinp();
}