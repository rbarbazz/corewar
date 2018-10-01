/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:37:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 15:18:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	convert_uint(t_asm *champ, unsigned int dec)
{
	char			size[5];
	unsigned int	len;

	len = 4;
	size[len] = 0;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	while (len < 4)
		champ->cor_file[champ->header->prog_size++] = size[len++];
}

void	convert_ushort(t_asm *champ, unsigned short dec)
{
	char			size[3];
	unsigned int	len;

	len = 2;
	size[len] = 0;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	while (len < 2)
		champ->cor_file[champ->header->prog_size++] = size[len++];
}

void	write_uint(t_asm *champ, unsigned int dec)
{
	char			size[5];
	unsigned int	len;

	len = 4;
	size[len] = 0;
	while (len)
	{
		size[len - 1] = dec % 256;
		dec /= 256;
		len--;
	}
	while (len < 4)
	{
		ft_dprintf(champ->fd, "%c", size[len]);
		len++;
	}
}
