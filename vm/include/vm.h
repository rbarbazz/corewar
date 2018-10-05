/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/10/05 15:54:45 by msamak           ###   ########.fr       */
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

# define FILE_LEN_MAX PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 12

/*
** *****************************************************************************
** Color
** *****************************************************************************
*/

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
	t_process			*process;
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
** Create list of player
** *****************************************************************************
*/

int						init_player(t_global *info, char *file);

/*
** *****************************************************************************
** Clock
** *****************************************************************************
*/

int						cycle(t_global *info);

/*
** *****************************************************************************
** Bonus
** *****************************************************************************
*/

int						bonus(t_global *info);

#endif
