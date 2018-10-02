/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:24:38 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/02 17:59:04 by rbarbazz         ###   ########.fr       */
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
		perror(filename);
		exit_fail();
	}
	ft_printf("Writing output program to %s\n", tmp);
	ft_strdel(&tmp);
	return (fd);
}

static char	*get_name(t_asm *champ)
{
	char	*res;

	if (!(res = ft_strnew(ft_strlen(champ->filename) - 2)))
		exit_fail();
	ft_strncpy(res, champ->filename, ft_strlen(champ->filename) - 2);
	return (res);
}

void		write_to_cor(t_asm *champ)
{
	char			*tmp;
	unsigned int	i;

	tmp = get_name(champ);
	champ->fd = open_file(tmp);
	ft_strdel(&tmp);
	write_header(champ);
	i = 0;
	while (i < champ->header->prog_size)
	{
		ft_dprintf(champ->fd, "%c", champ->cor_file[i]);
		i++;
	}
	if (close(champ->fd) == -1)
	{
		perror("close");
		exit_fail();
	}
}
