/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 17:04:43 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
** *****************************************************************************
** Library Included
** *****************************************************************************
*/

# include "../libft/include/libft.h"
# include "op.h"
# include <curses.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

/*
** *****************************************************************************
** Error Code
** *****************************************************************************
*/

# define SUCCESS				0
# define TOO_MANY_ARGS			1
# define FILE_EMPTY				2
# define READ_FILE_ERROR		3
# define MALLOC_ERROR			4
# define INVALID_MAGIC			5
# define WRONG_COMMAND_LENGTH	6
# define NO_CHAMP				7
# define INVALID_CLOSE_FD		8
# define USAGE_ERROR			9

# define FILE_LEN_MAX	PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 12

/*
** *****************************************************************************
** Color
** *****************************************************************************
*/

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BOLDBLACK  	"\033[1m\033[30m"
# define BOLDRED    	"\033[1m\033[31m"
# define BOLDGREEN  	"\033[1m\033[32m"
# define BOLDYELLOW 	"\033[1m\033[33m"
# define BOLDBLUE   	"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN   	"\033[1m\033[36m"
# define BOLDWHITE  	"\033[1m\033[37m"

/*
** *****************************************************************************
** Curses
** *****************************************************************************
*/

# define TOP_LINE			2
# define PLAYER_LINE		(TOP_LINE + 4)
# define SEP_COL			50
# define ARENA_START_COL	(SEP_COL + 2)
# define TOTAL_COLS			(ARENA_START_COL + (64 * 3) + 1)
# define TOTAL_LINES		(64 + (2 * 2))
# define LINES_LIM			(TOTAL_LINES + 3)
# define MSG_LINE			(TOTAL_LINES + 2)

/*
** *****************************************************************************
** Structure
** *****************************************************************************
*/

typedef struct			s_op
{
	char				name[6];
	int					nb_param;
	unsigned int		param[3];
	int					opcode;
	int					cycle;
	int					has_ocp;
	int					nb_or_address;
}						t_op;

typedef struct			s_process
{
	unsigned int		reg[REG_NUMBER];
	unsigned short		pc;
	int					carry;
	unsigned int		start_pos;
	unsigned int		curr_pos;
	unsigned int		visu_pos;
	int					cycle_left;
	t_op				curr_op;
	int					valid_ocp;
	unsigned int		type_param[3];
	int					has_live;
	struct s_process	*prev;
	struct s_process	*next;
}						t_process;

typedef struct			s_player
{
	int					player;
	char				*name;
	char				*comment;
	unsigned int		prog_size;
	char				*instruction;
	unsigned int		start;
	unsigned int		last_live;
	unsigned int		curr_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_map
{
	unsigned char		c;
	int					player;
	int					current;
	struct s_map		*prev;
	struct s_map		*next;
}						t_map;

typedef struct			s_cycle
{
	unsigned int		cycle;
	int					cycle_to_die;
	int					current_cycle;
	unsigned int		dump;
}						t_cycle;

typedef struct			s_global
{
	char				*prog_name;
	t_process			*process_head;
	t_process			*process_tail;
	int					process_count;
	t_player			*player;
	int					player_count;
	t_map				*map;
	t_cycle				clock;
	int					visual;
	int					dump;
}						t_global;

/*
** *****************************************************************************
** Get the Global Structure
** *****************************************************************************
*/

t_global				*get_global(void);
void					init_global(t_global *info, char *prog_name);

extern					t_op	g_op_tab[16];

/*
** *****************************************************************************
** Display
** *****************************************************************************
*/

int						print_map(t_global *info);
int						print_map(t_global *info);
int						print_player(t_global *info);
void					display_intro(t_global *info);

/*
** *****************************************************************************
** Exit and Free Functions
** *****************************************************************************
*/

void					exit_corewar(int error_code);
void					free_process(void);
void					free_all(void);
void					free_player(void);
void					free_map(void);
void					kill_process(t_global *info, t_process *process);

/*
** *****************************************************************************
** Open & Read Functions
** *****************************************************************************
*/

int						open_file(char *filename);
char					*read_file(int fd, char *filename);
void					close_file(int fd);

/*
** *****************************************************************************
** Parsing
** *****************************************************************************
*/

int						check_args(t_global *info, int argc, char **argv);
int						check_magic(char *file);

/*
** *****************************************************************************
** Create Map
** *****************************************************************************
*/

int						init_map(t_global *info, char c);
int						create_map(t_global *info);
void					write_player_in_map(t_global *info);

/*
** *****************************************************************************
** Create lists
** *****************************************************************************
*/

int						init_player(t_global *info, char *file);
void					create_initial_process(t_global *info);

/*
** *****************************************************************************
** Clock
** *****************************************************************************
*/

int						cycle(t_global *info);

/*
** *****************************************************************************
** Play, send the sauce
** *****************************************************************************
*/

int						play(t_global *info);
void					check_process(t_global *info);
char					get_ocp(t_global *info, t_process *process);
void					get_op(t_global *info, t_process *process);
char					*get_value_at_position(t_map *map,\
unsigned int position, int size);
int						get_data_from_op(int op, t_process *process);
void					get_op_param(t_global *info, t_process *process,\
unsigned char ocp);
void					do_op(t_global *info, t_process *process);

/*
** *****************************************************************************
** Functions OP
** *****************************************************************************
*/

void					live(t_global *info, t_process *process);
void					add(t_global *info, t_process *process);
void					sub(t_global *info, t_process *process);
void					zjmp(t_global *info, t_process *process);
void					aff(t_global *info, t_process *process);
void					lfork(t_global *info, t_process *process);
void					lld(t_global *info, t_process *process);




/*
** *****************************************************************************
** Tools
** *****************************************************************************
*/

unsigned int			tab_to_int(char *str);
char					*map_from_list(t_global *info);
void					set_current_null(t_map *map, int position);
void					increase_position(t_process *process,unsigned int add);

/*
** *****************************************************************************
** Map updater
** *****************************************************************************
*/

void					update_map(t_global *info);

/*
** *****************************************************************************
** Curses functions
** *****************************************************************************
*/

int						ft_visu_curses(t_global *info);
int						ft_init_curses(t_global *info);
int						ft_check_screen_size(void);

#endif
