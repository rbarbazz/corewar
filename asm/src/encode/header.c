/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:07:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/03 17:26:07 by rbarbazz         ###   ########.fr       */
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

/*
** *****************************************************************************
** first call to write_uint() to write COREWAR_EXEC_MAGIC
** second call to write_uint() to write prog_size
** *****************************************************************************
*/

void		write_header(t_asm *champ)
{
	int	i;

	i = 0;
	write_uint(champ, champ->header->magic);
	while (i < PROG_NAME_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->prog_name[i]);
		i++;
	}
	add_padding(champ, 4);
	write_uint(champ, champ->header->prog_size);
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->comment[i]);
		i++;
	}
	add_padding(champ, 4);
}
