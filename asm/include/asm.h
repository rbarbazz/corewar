/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 15:31:23 by rbarbazz         ###   ########.fr       */
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

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

# define T_REG				1
# define T_DIR				2
# define T_IND				4

# define COMMENT_CHAR 		'#'
# define LABEL_CHAR 		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define REG_NUMBER			16

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

# define WRONG_USAGE 1
# define FILE_EMPTY 2
# define WRONG_CMD 3
# define WRONG_CMD_VALUE 4
# define CMD_TOO_BIG 5
# define PARSE_ERR 6

typedef struct		s_lab
{
	char			*name;
	int				pos;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_op
{
	char			name[6];
	int				nb_param;
	int				param[3];
	int				opcode;
	int				has_ocp;
	int				nb_or_address;
}					t_op;

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
	t_lab			*lab;
	t_op			*op;
	int				curr_ocp;
}					t_asm;

t_asm				*get_champ(void);

extern				t_op	g_op_tab[16];

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
int					skip_non_print(void);
void				skip_space(void);
void				move_index(void);
void				look_for_label(t_asm *champ);
void				look_for_op(t_asm *champ);
int					check_op_name(t_asm *champ);
void				check_op_param(t_asm *champ, t_op *op);

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
