/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 17:42:42 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** adds one line to the stored sfile without comments
*/

void		store_line(t_sfile **sfile, char *line)
{
	t_sfile	*tmp;
	t_sfile	*new;

	tmp = *sfile;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_sfile*)ft_memalloc(sizeof(t_sfile))))
		exit_fail();
	if (!tmp)
		*sfile = new;
	else
		tmp->next = new;
	if (!(new->line = dup_to_char(line, COMMENT_CHAR)))
		exit_fail();
}

static int	open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("'%s': %s\n", filename, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/*
** stores the input sfile without comments
*/

int			store_sfile(char *filename, t_sfile **sfile)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open_file(filename);
	while (get_next_line(fd, &line) == 1)
	{
		store_line(sfile, line);
		ft_strdel(&line);
	}
	if (close(fd) == -1)
	{
		ft_printf("'%d': %s\n", fd, strerror(errno));
		exit_fail();
	}
	return (0);
}