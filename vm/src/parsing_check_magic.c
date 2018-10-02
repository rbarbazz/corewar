/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_magic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:28:20 by msamak            #+#    #+#             */
/*   Updated: 2018/10/02 19:29:59 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	*uitoa_d(unsigned int dec)
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
	return (ft_strndup(size, 4));
}

int			check_magic(char *file)
{
	char	*exec;
	int		i;

	exec = uitoa_d(COREWAR_EXEC_MAGIC);
	i = 0;
	while (i < 4)
	{
		if (exec[i] != file[i])
		{
			ft_strdel(&exec);
			return (1);
		}
		i++;
	}
	ft_strdel(&exec);
	return (0);
}
