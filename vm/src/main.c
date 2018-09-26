/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/26 17:04:58 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	ft_bzero(info->map, MEM_SIZE);
	info->process = NULL;
	ft_bzero(info->player_tab, MAX_PLAYERS);
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

int			print_map(t_global *info)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%d", info->map[i]);
		i++;
	}
	return (0);
}

int		main(void)
{
	t_global	*info;

	info = get_global();
	ft_printf("Bienvenue dans CoreWar\n");
	print_map(info);
	return (0);
}
