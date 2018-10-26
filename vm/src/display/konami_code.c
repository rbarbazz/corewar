/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   konami_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:56:11 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/26 19:56:30 by lcompagn         ###   ########.fr       */
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
	attron(COLOR_PAIR(5));
	while (++i < MEM_SIZE)
	{
		mvprintw(line, col, "   ");
		if ((col += 3) > (TOTAL_COLS - 4))
		{
			col = ARENA_START_COL;
			line++;
		}
	}
	attroff(COLOR_PAIR(5));
}

static void	print_easter(void)
{
	int		line;
	int		col;
	int		i;
	int		len;
	char	*pic;

	clear_arena();
	if (!(pic = ft_strdup(NOTRE_IMAGE_EN_DUR)))
		return ;
	len = ft_strlen(pic);
	i = -1;
	line = TOP_LINE;
	col = ARENA_START_COL;
	while (++i < len)
		if (pic[i] && pic[i] == '\n')
		{
			i++;
			line++;
			col = ARENA_START_COL;
		}
		else
			mvprintw(line, col++, "%c", pic[i]);
	ft_strdel(&pic);
	getch();
	clear_arena();
}

void		konami_code(void)
{
	int		key;

	if ((key = getch()) == KEY_UP)
		if ((key = getch()) == KEY_DOWN)
			if ((key = getch()) == KEY_DOWN)
				if ((key = getch()) == KEY_LEFT)
					if ((key = getch()) == KEY_RIGHT)
						if ((key = getch()) == KEY_LEFT)
							if ((key = getch()) == KEY_RIGHT)
								if ((key = getch()) == KEY_B)
									if ((key = getch()) == KEY_A)
										if ((key = getch()) == KEY_PAUSE)
											print_easter();
}
