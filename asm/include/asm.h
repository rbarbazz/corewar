/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/04 18:59:17 by rbarbazz         ###   ########.fr       */
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

/*
** *****************************************************************************
** size in byte of each param type
** *****************************************************************************
*/

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

/*
** *****************************************************************************
** param type number
** *****************************************************************************
*/

typedef char				t_arg_type;

# define T_REG				1
# define T_DIR				2
# define T_IND				4

/*
** *****************************************************************************
** param type ocp coresponding code
** *****************************************************************************
*/

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

/*
** *****************************************************************************
** parsing values
** *****************************************************************************
*/

# define COMMENT_CHAR 		'#'
# define LABEL_CHAR 		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

/*
** *****************************************************************************
** sizes
** *****************************************************************************
*/

# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define REG_NUMBER			16
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)

/*
** *****************************************************************************
** error codes
** *****************************************************************************
*/

# define WRONG_USAGE 		1
# define FILE_EMPTY 		2
# define WRONG_CMD 			3
# define WRONG_CMD_VALUE 	4
# define CMD_TOO_BIG 		5
# define PARSE_ERR 			6
# define LAB_NOT_DEFINED	7
# define CHAMP_TOO_BIG		8
# define ERR_SEP			9
# define WRONG_REG			10

# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct				s_lab_pos
{
	char					*name;
	int						pos;
	int						op_pos;
	int						size;
	int						col;
	int						line;
	struct s_lab_pos		*next;
}							t_lab_pos;

typedef struct				s_lab
{
	char					*name;
	long					pos;
	struct s_lab			*prev;
	struct s_lab			*next;
}							t_lab;

typedef struct				s_op
{
	char					name[6];
	int						nb_param;
	int						param[3];
	int						opcode;
	int						has_ocp;
	int						nb_or_address;
}							t_op;

typedef struct				s_header
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
}							t_header;

typedef struct				s_asm
{
	char					*filename;
	char					*sfile;
	t_header				*header;
	int						line;
	int						col;
	int						i;
	int						fd;
	char					cor_file[CHAMP_MAX_SIZE + 1];
	t_lab					*lab;
	t_lab_pos				*lab_pos;
	t_op					*op;
	unsigned int			curr_ocp;
	unsigned int			curr_op_pos;
}							t_asm;

extern						t_op	g_op_tab[16];

t_asm						*get_champ(void);

/*
** *****************************************************************************
** first error handling : check arguments and arguments syntax
** *****************************************************************************
*/

int							check_file_extension(char *filename);
char						*check_args(int argc, char **argv);

/*
** *****************************************************************************
** parsing
** *****************************************************************************
*/

char						*store_sfile(char *filename);
int							parser(t_asm *champ);
void						check_cmd(t_asm *champ, char *cmd);
void						check_cmd_value(t_asm *champ, int max_length,\
char *cmd, char *value);
void						look_for_label(t_asm *champ);
int							is_label_chars(char c);
void						look_for_op(t_asm *champ);
int							check_op_name(t_asm *champ);
void						check_op_param(t_asm *champ, t_op *op);
void						check_param_type(t_arg_type type, t_op *op, \
int curr_param);
int							check_reg(t_asm *champ, t_op *op, int curr_param);
int							check_dir(t_asm *champ, t_op *op, int curr_param);
int							check_ind(t_asm *champ, t_op *op, int curr_param);
int							get_label_pos(t_asm *champ, int size);
long						get_whole_value(t_asm *champ);
void						check_label_pos(t_asm *champ);
t_lab						*check_lab_exist(t_asm *champ, char *lab_name);

/*
** *****************************************************************************
** splitting ints into bytes
** *****************************************************************************
*/

void						convert_uint(t_asm *champ, unsigned int dec);
void						convert_ushort(t_asm *champ, unsigned short dec);
void						write_uint(t_asm *champ, unsigned int dec);

/*
** *****************************************************************************
** cursor motion during the parsing to provide relevant error messages
** *****************************************************************************
*/

int							skip_non_print(void);
void						skip_space(void);
void						move_index(void);

/*
** *****************************************************************************
** creating and writing to .cor file
** *****************************************************************************
*/

void						write_to_cor(t_asm *champ);
void						write_header(t_asm *champ);

/*
** *****************************************************************************
** error handling
** *****************************************************************************
*/

void						error_usage(char *prog_name);
void						error_empty(void);
void						error_parse(void);
void						error_cmd(char *cmd);
void						error_cmd_value(char *cmd);
void						error_cmd_length(char *cmd, int max_length);
void						error_lab(t_lab_pos *lab_pos);
void						error_size(void);
void						error_separator(void);
void						error_reg(void);

/*
** *****************************************************************************
** memory clearing and exit
** *****************************************************************************
*/

void						free_asm(void);
void						exit_fail(void);

#endif
