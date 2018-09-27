/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 12:21:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*remove_comment(char *line)
{
	char	*no_comment;

	if (!(no_comment = dup_to_char(line, COMMENT_CHAR)))
	{
		ft_strdel(&line);
		exit_fail();
	}
	ft_strdel(&line);
	return (no_comment);
}

/*
** adds one line to the stored sfile
*/

static void	store_line(char **sfile, char *line)
{
	char	*tmp;

	if (!*sfile)
	{
		if (!(*sfile = ft_strdup(line)))
		{
			ft_strdel(&line);
			exit_fail();
		}
	}
	else
	{
		tmp = *sfile;
		if (!(*sfile = ft_strjoin(tmp, line)))
		{
			ft_strdel(&line);
			exit_fail();
		}
		ft_strdel(&tmp);
	}
	ft_strdel(&line);
	if (!(*sfile = strjoinchar(*sfile, '\n')))
		exit_fail();
}

static int	open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/*
** stores the input sfile without comments
*/

char		*store_sfile(char *filename)
{
	int		fd;
	char	*line;
	char	*sfile;

	line = NULL;
	sfile = NULL;
	fd = open_file(filename);
	while (get_next_line(fd, &line) == 1)
	{
		line = remove_comment(line);
		store_line(&sfile, line);
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit_fail();
	}
	return (sfile);
}
