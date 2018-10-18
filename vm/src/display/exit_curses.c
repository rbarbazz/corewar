/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_curses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:04:55 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/15 13:59:07 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_clear_space(int col, int line, int len)
{
	int		pos;

	while (line <= (TOTAL_LINES / 2) + 2)
	{
		pos = col - 1;
		while (++pos <= col + len + 2)
			mvprintw(line, pos, " ");
		line++;
	}
}

void		ft_exit_curses(t_player *winner)
{
	int		line;
	int		col;
	int		len;

	nodelay(stdscr, FALSE);
	line = (TOTAL_LINES / 2) - 2;
	col = (TOTAL_COLS + SEP_COL) / 2;
	len = ft_strlen("And the winner is : Player x () !!!");
	len += ft_strlen(winner->name);
	col = col - (len / 2) - 2;
	ft_clear_space(col, line, len);
	attron(COLOR_PAIR(winner->player));
	mvprintw(line + 1, col + 1, "And the winner is : Player %d (%s) !!!",
			winner->player, winner->name);
	attroff(COLOR_PAIR(winner->player));
	mvprintw(line + 3, col + 1, "Press any key");
	getch();
	endwin();
}
