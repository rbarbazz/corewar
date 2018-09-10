/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 15:25:04 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		store_line(t_sfile **sfile, char *line)
{
	t_sfile	*tmp;
	t_sfile	*new;

	tmp = *sfile;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_sfile*)ft_memalloc(sizeof(t_sfile))))
		exit(EXIT_FAILURE);
	if (!tmp)
		*sfile = new;
	else
		tmp->next = new;
	if (!(new->line = ft_strdup(line)))
		exit(EXIT_FAILURE);
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
	return (0);
}