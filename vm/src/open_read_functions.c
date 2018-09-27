/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:45:44 by msamak            #+#    #+#             */
/*   Updated: 2018/09/27 18:51:35 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*read_file(int fd, char *filename)
{
	char	*file;
	int		ret;

	if (!(file = (char *)ft_memalloc(sizeof(char) * FILE_LEN_MAX)))
		exit_corewar(MALLOC_ERROR);
	ft_bzero(file, FILE_LEN_MAX);
	ret = read(fd, file, FILE_LEN_MAX);
	if (ret < 0)
	{
		ft_strdel(&file);
		perror(filename);
		exit_corewar(FILE_READ_ERROR);
	}
	if (ret == 0)
	{
		ft_strdel(&file);
		exit_corewar(FILE_EMPTY);
	}
	return (file);
}
