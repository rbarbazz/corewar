/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:45:44 by msamak            #+#    #+#             */
/*   Updated: 2018/10/28 15:20:45 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror(filename);
		exit_corewar(INVALID_CLOSE_FD);
	}
	return (fd);
}

char	*read_file(int fd, char *filename)
{
	char	*file;
	int		ret;

	if (!(file = (char*)ft_memalloc(sizeof(char)\
		* FILE_LEN_MAX + 1)))
		exit_corewar(MALLOC_ERROR);
	ft_bzero(file, FILE_LEN_MAX);
	if ((ret = read(fd, file, FILE_LEN_MAX + 1)) < 0)
	{
		ft_strdel(&file);
		perror(filename);
		exit_corewar(READ_FILE_ERROR);
	}
	if (ret == 0)
	{
		ft_strdel(&file);
		exit_corewar(FILE_EMPTY);
	}
	if (ret > FILE_LEN_MAX)
	{
		ft_strdel(&file);
		exit_corewar(WRONG_COMMAND_LENGTH);
	}
	return (file);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
	{
		perror("close");
		exit_corewar(INVALID_CLOSE_FD);
	}
}
