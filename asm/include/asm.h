/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/24 15:34:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define COMMENT_CHAR 		'#'
# define LABEL_CHAR 		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

#define MEM_SIZE			(4*1024)
#define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

# define WRONG_USAGE 1
# define FILE_EMPTY 2
# define WRONG_CMD 3
# define WRONG_CMD_VALUE 4
# define CMD_TOO_BIG 5
# define PARSE_ERR 6

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_asm
{
	char			*filename;
	char			*sfile;
	t_header		*header;
	int				line;
	int				col;
	int				i;
	int				fd;
	char			cor_file[CHAMP_MAX_SIZE + 1];
}					t_asm;

t_asm				*get_champ(void);

/*
** check arguments
*/

int					check_file_extension(char *filename);
char				*check_args(int argc, char **argv);

/*
** parsing
*/

char				*store_sfile(char *filename);
int					parser(t_asm *champ);
void				check_cmd(t_asm *champ, char *cmd);
void				check_cmd_value(t_asm *champ, int max_length, char *cmd,\
char *value);
void				skip_non_print(t_asm *champ);
void				skip_space(t_asm *champ);
void				move_index(t_asm *champ);

/*
** creating and writing to .cor file
*/

void				write_to_cor(t_asm *champ);
void				write_header(t_asm *champ);

/*
** error
*/

void				error_usage(char *prog_name);
void				error_empty(void);
void				error_parse(void);
void				error_cmd(char *cmd);
void				error_cmd_value(char *cmd);
void				error_cmd_length(char *cmd, int max_length);

/*
** clear
*/

void				free_asm(void);
void				exit_fail(void);

#endif
