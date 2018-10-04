/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/10/04 19:41:07 by msamak           ###   ########.fr       */
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
# define COMMAND_LENGTH_NOT_CORRESPOND 6

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
	short				pc;
	int					carry;
	int					postion;
	struct s_process	*next;
}						t_process;

typedef struct			s_player
{
	int					player;
	char				*name;
	char				*comment;
	unsigned int		command_size;
	char				*command;
	struct s_player		*next;
}						t_player;

typedef struct			s_map
{
	char				c;
	int					player;
	int					current;
	struct s_map		*next;
}						t_map;

typedef struct			s_global
{
	t_process			*process;
	t_player			*player;
	int					player_count;
	t_map				*map_list;
	int					visual;
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
int						print_map_list(t_global *info);
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
int						get_list_from_map(t_global *info);
int						write_player_in_map(t_global *info);

/*
** *****************************************************************************
** Create list of player
** *****************************************************************************
*/

int						init_player(t_global *info, char *file);

#endif
