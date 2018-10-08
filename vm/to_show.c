//POUR LE .H
int	ft_visu(int cycle, int cycle_to_die, int current_cycle);
#define TOP_LINE 2
#define SEP_COL (COLS / 5)
#define INFO_START_COL 2
#define ARENA_START_COL (SEP_COL + 2)
#define PLAYER_LINE (TOP_LINE + 4)


//POUR LE MAIN
//  --> juste avant le while
initscr();
//  --> juste avant la fin du while
ft_visu(cycle, cycle_to_die, current_cycle);
//  --> apres le while
getch();
endwin();

//VISU .c (a ajouter dans le makefile)
#include "vm.h"
void	ft_drawbox(void)
{
	int	i;

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
		mvprintw(PLAYER_LINE + ((i - 1) * 4), INFO_START_COL, \
		"Player -%d: %s", i, player->name);
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 1, INFO_START_COL, \
		"  Last live:");
		mvprintw(PLAYER_LINE + ((i - 1) * 4) + 2, INFO_START_COL, \
		"  Lives in current period:");
		player = player->next;
		i++;
	}
	return (PLAYER_LINE + (4 * (i - 1)));
}

char	*ft_color(int player)
{
	if (player == 1)
		return (GREEN);
	else if (player == 2)
		return (BLUE);
	else if (player == 3)
		return (YELLOW);
	else
		return (MAGENTA);
}

void	ft_print_map(void)
{
	t_global	*env;
	t_map		*map;
	int		col;
	int		line;

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

	env = get_global();
	map = env->map_list;
	line = TOP_LINE;
	col = ARENA_START_COL;
	while (map)
	{
		attron(COLOR_PAIR(map->player));
		mvprintw(line, col, "%02X", 0xFF & map->c);
		attroff(COLOR_PAIR(map->player));
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
	ft_drawbox();
	ft_print_info(cycle, cycle_to_die, current_cycle);
	ret = ft_print_player();
mvprintw(ret, 2, "Some more ?");
	ft_print_map();
	refresh();
	getch();
	return (SUCCESS);
}
