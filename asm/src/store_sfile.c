/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:46:27 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 12:27:03 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/*
** stores the input sfile without comments
*/

int	store_sfile(char *filename, t_sfile **sfile)
{
	int		fd;
	char	*line;

	sfile = NULL;
	line = NULL;
	fd = open_file(filename);
	while (get_next_line(fd, &line) == 1)
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}