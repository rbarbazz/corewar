/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:24:38 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 19:03:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			dec_to_hex(int dec)
{
	char	*res;
	int		ret;

	if (!(res = ft_itoa(dec, 16, 0)))
		exit_fail();
	ret = atoi(res);
	ft_strdel(&res);
	return (ret);
}

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

void		write_to_cor(t_asm *champ)
{
	char			*tmp;
	unsigned int	i;

	if (!(tmp = dup_to_char(champ->filename, '.')))
		exit_fail();
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
