/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:24:38 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/14 21:18:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_file(char *filename)
{
	int		fd;
	char	*tmp;

	if (!(tmp = ft_strjoin(filename, ".cor")))
		exit_fail();
	if ((fd = open(tmp, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	{
		ft_strdel(&tmp);
		perror("open");
		exit(EXIT_FAILURE);
	}
	ft_strdel(&tmp);
	return (fd);
}


void	write_to_cor(t_asm *champ)
{
	char		*tmp;

	if (!(tmp = dup_to_char(champ->filename, '.')))
		exit_fail();
	champ->fd = open_file(tmp);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0xea);
	ft_dprintf(champ->fd, "%c", 0x83);
	ft_dprintf(champ->fd, "%c", 0xf3);
	ft_strdel(&tmp);
}
