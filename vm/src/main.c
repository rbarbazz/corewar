/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 18:55:13 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	ft_bzero(info->map, MEM_SIZE);
	info->process = NULL;
	ft_bzero(info->player_tab, MAX_PLAYERS);
	info->visual = 0;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

int			main(int argc, char **argv)
{
	t_global	*info;

	info = get_global();
	check_args(info, argc, argv);
	return (0);
}
