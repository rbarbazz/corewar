/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:07:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 16:08:23 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_padding(t_asm *champ, unsigned int padding)
{
	while (padding)
	{
		ft_dprintf(champ->fd, "%c", 0x00);
		padding--;
	}
}

static void	write_uint(t_asm *champ, unsigned int dec, unsigned int len)
{
	char	size[len + 1];

	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	size[len] = 0;
	while (len < 4)
	{
		ft_dprintf(champ->fd, "%c", size[len]);
		len++;
	}
}

/*
** first call to write_uint() to write COREWAR_EXEC_MAGIC
** second call to write_uint() to write prog_size
*/

void		write_header(t_asm *champ)
{
	int	i;

	i = 0;
	write_uint(champ, champ->header->magic, 4);
	while (i < PROG_NAME_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->prog_name[i]);
		i++;
	}
	add_padding(champ, 4);
	write_uint(champ, champ->header->prog_size, 4);
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->comment[i]);
		i++;
	}
	add_padding(champ, 4);
}
