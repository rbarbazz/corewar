/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:07:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/20 18:16:09 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_padding(t_asm *champ, int padd)
{
	while (padd)
	{
		ft_dprintf(champ->fd, "%c", 0x00);
		padd--;
	}
}

static void	write_size(t_asm *champ)
{
	add_padding(champ, 4);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0x17);
}

static void	write_exec_magic(t_asm *champ)
{
	ft_dprintf(champ->fd, "%c", 0x00);
	ft_dprintf(champ->fd, "%c", 0xea);
	ft_dprintf(champ->fd, "%c", 0x83);
	ft_dprintf(champ->fd, "%c", 0xf3);
}

void		write_header(t_asm *champ)
{
	int	i;

	i = 0;
	write_exec_magic(champ);
	while (i < PROG_NAME_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->prog_name[i]);
		i++;
	}
	write_size(champ);
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		ft_dprintf(champ->fd, "%c", champ->header->comment[i]);
		i++;
	}
	add_padding(champ, 4);
}
