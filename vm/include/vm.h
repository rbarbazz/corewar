/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/09/27 19:03:56 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../libft/include/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

/*
** Error Code
*/

# define TOO_MANY_ARGS 1
# define FILE_EMPTY 2
# define READ_FILE_ERROR 3
# define MALLOC_ERROR 4

# define FILE_LEN_MAX PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 12

typedef struct			s_process
{
	char				reg[REG_NUMBER][REG_SIZE];
	short				pc;
	int					carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_player
{
	int					player;
	char				*name;
	char				*comment;
}						t_player;

typedef struct			s_global
{
	char				map[MEM_SIZE];
	t_process			*process;
	t_player			player_tab[MAX_PLAYERS];
	int					visual;
}						t_global;

/*
** Get the Global Structure
*/

t_global				*get_global(void);

/*
** Debug Functions
*/

int						print_map(t_global *info);

/*
** Exit Functions
*/

void					exit_corewar(int error_code);

/*
** Open & Read Functions
*/

int						open_file(char *filename);
char					*read_file(int fd, char *filename);

/*
** Parsing
*/

int						check_champ(t_global *info, char *filename);
int						check_visual(t_global *info, int argc, char **argv);
int						check_args(t_global *info, int argc, char **argv);

#endif
