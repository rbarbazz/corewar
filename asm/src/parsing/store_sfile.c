/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 18:34:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** adds one line to the stored sfile
*/

static void	store_line(char **sfile, char *line)
{
	char	*wo_comm;
	char	*tmp;

	if (!(wo_comm = dup_to_char(line, COMMENT_CHAR)) ||\
	!(wo_comm = strjoinchar(wo_comm, '\n')))
		exit_fail();
	if (!*sfile)
	{
		if (!(*sfile = ft_strdup(wo_comm)))
			exit_fail();
	}
	else
	{
		tmp = *sfile;
		if (!(*sfile = ft_strjoin(tmp, wo_comm)))
			exit_fail();
		ft_strdel(&tmp);
	}
	ft_strdel(&wo_comm);
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
