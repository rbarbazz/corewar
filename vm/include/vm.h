/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 15:41:52 by msamak           ###   ########.fr       */
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
# include <time.h>

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
# define WRONG_PNUMBER			10

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

# define HIGHLIGHT_TIME				50
# define TOP_LINE					2
# define SLEEP_LINE					(TOP_LINE + 2)
# define CYCLE_LINE					(SLEEP_LINE + 2)
# define PLAYER_LINE				(CYCLE_LINE + 4)
# define SEP_COL					50
# define ARENA_START_COL			(SEP_COL + 2)
# define TOTAL_COLS					(ARENA_START_COL + (64 * 3) + 1)
# define TOTAL_LINES				(64 + (2 * 2))
# define LINES_LIM					(TOTAL_LINES + 3)
# define INSTRUCTION_LINE			(TOTAL_LINES - 8)
# define SLEEP_DEF					50000
# define SLEEP_DELTA				5000
# define SLEEP_LIM_INF				0
# define SLEEP_LIM_SUP				1000000
# define CYCLE_PER_SEC_UPDATE		50
# define KEY_PAUSE					' '
# define KEY_STEP					's'
# define KEY_SLEEP_UP				'-'
# define KEY_SLEEP_DOWN				'+'
# define RESIZE_SIGNAL				410

/*
** *****************************************************************************
** Structure
** *****************************************************************************
*/

typedef struct			s_op
{
	char				name[6];
	int					nb_param;
	int					param[3];
	int					opcode;
	int					cycle;
	char				has_ocp;
	char				nb_or_address;
}						t_op;

typedef struct			s_process
{
	struct s_process	*prev;
	struct s_process	*next;
	t_op				curr_op;
	int					reg[REG_NUMBER];
	int					carry;
	int					process_nb;
	int					op_pnumber;
	unsigned int		start_pos;
	unsigned int		curr_pos;
	unsigned int		visu_pos;
	unsigned int		op_pos;
	unsigned int		op_pc;
	int					cycle_left;
	unsigned int		type_param[3];
	unsigned short		pc;
	char				has_live;
	char				valid_ocp;
}						t_process;

typedef struct			s_player
{
	struct s_player		*next;
	struct s_player		*prev;
	char				*name;
	char				*comment;
	char				*instruction;
	int					pnumber;
	int					player;
	unsigned int		prog_size;
	unsigned int		start;
	unsigned int		last_live;
	unsigned int		curr_live;
}						t_player;

typedef struct			s_map
{
	struct s_map		*prev;
	struct s_map		*next;
	int					pnumber;
	int					cycle_written;
	unsigned char		c;
	char				current;
}						t_map;

typedef struct			s_cycle
{
	unsigned int		cycle;
	int					cycle_to_die;
	int					current_cycle;
	unsigned int		dump;
	int					curr_live;
	char				checks;
}						t_cycle;

typedef struct			s_global
{
	char				visu_pos[MEM_SIZE];
	t_cycle				clock;
	t_process			*process_head;
	t_process			*process_tail;
	t_player			*player_head;
	t_player			*player_tail;
	t_map				*map;
	char				*prog_name;
	int					process_count;
	int					player_count;
	int					next_pnumber;
	int					sleep;
	char				visual;
	char				debug;
	char				dump;
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

void					create_map(t_global *info);
void					write_player_in_map(t_global *info);

/*
** *****************************************************************************
** Create lists
** *****************************************************************************
*/

int						init_player(t_global *info, char *file,\
char has_pnumber);
void					create_initial_process(t_global *info);
t_process				*dup_process(t_global *info, t_process *process);

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
int						get_op_pnumber(t_global *info, unsigned int curr_pos);
int						get_data_from_op(int op, t_process *process);
char					*get_value_at_position(t_map *map,\
unsigned int position, int size);
void					get_op_param(t_global *info, t_process *process,\
unsigned char ocp);
void					do_op(t_global *info, t_process *process);

/*
** *****************************************************************************
** Functions OP
** *****************************************************************************
*/

int						get_param_value(t_global *info, t_process *process,\
int i, int *param);
int						check_reg(t_global *info, t_process *process, int i);
void					live(t_global *info, t_process *process);
void					add(t_global *info, t_process *process);
void					sub(t_global *info, t_process *process);
void					zjmp(t_global *info, t_process *process);
void					aff(t_global *info, t_process *process);
void					lfork(t_global *info, t_process *process);
void					lld(t_global *info, t_process *process);
void					lldi(t_global *info, t_process *process);
void					ld(t_global *info, t_process *process);
void					st(t_global *info, t_process *process);
void					sti(t_global *info, t_process *process);
void					ldi(t_global *info, t_process *process);
void					fork_vm(t_global *info, t_process *process);
void					and_vm(t_global *info, t_process *process);
void					or_vm(t_global *info, t_process *process);
void					xor_vm(t_global *info, t_process *process);

/*
** *****************************************************************************
** Tools
** *****************************************************************************
*/

int						tab_to_int(char *str);
char					*uitoa_d(unsigned int dec);
char					*map_from_list(t_global *info);
void					set_current_null(t_map *map, int position);
void					increase_position(t_process *process,unsigned int add);
void					write_at_position(t_map *map, t_process *process, \
unsigned int position, unsigned int buff);
void					ft_carry(t_process *process, int value);

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

int						ft_check_screen_size(void);
int						ft_init_curses(t_global *info);
void					ft_init_permanent_parts(t_global *info);
void					ft_print_instructions(void);
int						ft_visu_curses(t_global *info);
void					ft_curses_map(t_global *info);
void					ft_exit_curses(t_player *winner);
void					ft_get_input(t_global *info);
int						get_p_id(t_global *info, int pnum);

#endif
