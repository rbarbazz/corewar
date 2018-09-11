/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 13:15:23 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** adds one line to the stored sfile
*/

static void	store_line(char **sfile, char *line)
{
	char	*tmp;

	if (!(line = dup_to_char(line, COMMENT_CHAR)))
		exit_fail();
	if (line[0])
	{
		if (!(tmp = strjoinchar(line, '\n')))
			exit_fail();
	}
	ft_strdel(&tmp);
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
		store_line(&sfile, line);
		ft_strdel(&line);
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit_fail();
	}
	return (sfile);
}