/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 17:44:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

typedef struct		s_sfile
{
	char			*line;
	struct s_sfile	*next;
}					t_sfile;

typedef struct		s_asm
{
	t_sfile			*sfile;
	char			*name;
	char			*comment;
}					t_asm;

t_asm	*get_champ(void);

/*
** check arguments
*/

int		check_file_extension(char *filename);
char	*check_args(int argc, char **argv);


/*
** store sfile
*/

int		store_sfile(char *filename, t_sfile **sfile);

/*
** display
*/

void	display_sfile(t_sfile *sfile);
void	display_usage(char *prog_name);

/*
** clear
*/

void	free_asm(void);
void	exit_fail(void);

#endif