/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 16:23:30 by rbarbazz         ###   ########.fr       */
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

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_asm
{
	char			*sfile;
	t_header		*header;
	int				line;
	int				col;
	int				i;
}					t_asm;

t_asm	*get_champ(void);

/*
** check arguments
*/

int		check_file_extension(char *filename);
char	*check_args(int argc, char **argv);


/*
** parsing
*/

char	*store_sfile(char *filename);
int		parser(t_asm *champ);

/*
** display
*/

void	display_champ(t_asm *champ);
void	display_usage(char *prog_name);
void	display_error_parse(void);

/*
** clear
*/

void	free_asm(void);
void	exit_fail(void);

#endif