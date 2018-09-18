/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:24:38 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/18 11:08:13 by rbarbazz         ###   ########.fr       */
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
		exit_fail();
	}
	ft_printf("Writing output program to %s\n", tmp);
	ft_strdel(&tmp);
	return (fd);
}

static void	write_header(t_asm *champ)
{
	int	i;

	i = 0;
	while (i < PROG_NAME_LENGTH + 1)
	{
		ft_dprintf(champ->fd, "%c", champ->header->prog_name[i]);
		i++;
	}
	/*// hardcoded size for test.s
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x17);
	i = 0;
	while (i < COMMENT_LENGTH + 1)
	{
		ft_dprintf(champ->fd, "%c", champ->header->comment[i]);
		i++;
	}*/
}

void	write_to_cor(t_asm *champ)
{
	char		*tmp;

	if (!(tmp = dup_to_char(champ->filename, '.')))
		exit_fail();
	champ->fd = open_file(tmp);
	ft_strdel(&tmp);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0xea);
	ft_dprintf(champ->fd, "%c", 0x83);
	ft_dprintf(champ->fd, "%c", 0xf3);
	write_header(champ);
}
