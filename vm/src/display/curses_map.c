/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:23:00 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/17 19:23:36 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_curses_map(t_global *info)
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
		if (map->cycle_written > (int)info->clock.cycle)
			attron(A_BOLD | COLOR_PAIR(get_p_id(info, map->pnumber) | (map->current << 3)));
		else
			attron(COLOR_PAIR(get_p_id(info, map->pnumber) | (map->current << 3)));
		mvprintw(line, col, "%02X", 0xFF & map->c);
		if (map->cycle_written > (int)info->clock.cycle)
			attroff(A_BOLD | COLOR_PAIR(get_p_id(info, map->pnumber) | (map->current << 3)));
		else
			attroff(COLOR_PAIR(get_p_id(info, map->pnumber) | (map->current << 3)));
		col = col + 3;
		if (col > (TOTAL_COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
		map = map->next;
	}
}
