/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/10/05 18:47:58 by rbarbazz         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>

/*
** *****************************************************************************
** Error Code
** *****************************************************************************
*/

# define SUCCESS 0
# define TOO_MANY_ARGS 1
# define FILE_EMPTY 2
# define READ_FILE_ERROR 3
# define MALLOC_ERROR 4
# define INVALID_MAGIC 5
# define WRONG_COMMAND_LENGTH 6
# define NO_CHAMP 7
# define INVALID_CLOSE_FD 8

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
** Structure
** *****************************************************************************
*/

typedef struct			s_process
{
	char				reg[REG_NUMBER][REG_SIZE];
	unsigned short		pc;
	int					carry;
	int					position;
	int					cycle_left;
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
	int					start;
	int					last_live;
	int					curr_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_map
{
	char				c;
	int					player;
	int					current;
	struct s_map		*next;
}						t_map;

typedef struct			s_cycle
{
	int					cycle;
	int					cycle_to_die;
	int					current_cycle;
}						t_cycle;

typedef struct			s_global
{
	t_process			*process_head;
	t_process			*process_tail;
	int					process_count;
	t_player			*player;
	int					player_count;
	t_map				*map;
	int					visual;
	t_cycle				clock;
}						t_global;

/*
** *****************************************************************************
** Get the Global Structure
** *****************************************************************************
*/

t_global				*get_global(void);

/*
** *****************************************************************************
** Debug Functions
** *****************************************************************************
*/

int						print_map(t_global *info);
int						print_map(t_global *info);
int						print_player(t_global *info);
/*
** *****************************************************************************
** Exit Functions
** *****************************************************************************
*/

void					exit_corewar(int error_code);

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

int						check_champ(t_global *info, char *filename);
int						check_visual(t_global *info, int argc, char **argv);
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

void					check_process(t_global *info);

/*
** *****************************************************************************
** Bonus
** *****************************************************************************
*/

int						bonus(t_global *info);

#endif
