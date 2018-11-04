/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:56:11 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/31 08:08:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	clear_arena(void)
{
	int		line;
	int		col;
	int		i;

	line = 2;
	col = ARENA_START_COL;
	i = -1;
	attron(COLOR_PAIR(5) | A_STANDOUT);
	while (++i < MEM_SIZE)
	{
		mvprintw(line, col, "   ");
		if ((col += 3) > (TOTAL_COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
	}
	attroff(COLOR_PAIR(5) | A_STANDOUT);
}

static void	print_pic(void)
{
	int		fd;
	int		line;
	char	*pic_line;

	if ((fd = open(".pic", O_RDONLY)) == -1)
		return ;
	clear_arena();
	line = TOP_LINE;
	attron(COLOR_PAIR(5));
	while (get_next_line(fd, &pic_line))
	{
		mvprintw(line, ARENA_START_COL, "%s", pic_line);
		ft_strdel(&pic_line);
		line++;
	}
	ft_strdel(&pic_line);
	attroff(COLOR_PAIR(5));
	close(fd);
	refresh();
	getch();
	clear_arena();
}

void		fun_code(void)
{
	if (getch() == KEY_UP)
		if (getch() == KEY_DOWN)
			if (getch() == KEY_DOWN)
				if (getch() == KEY_LEFT)
					if (getch() == KEY_RIGHT)
						if (getch() == KEY_LEFT)
							if (getch() == KEY_RIGHT)
								if ((char)getch() == 'b')
									if ((char)getch() == 'a')
										print_pic();
}
