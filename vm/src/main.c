/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/04 22:58:02 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	info->process = NULL;
	info->player = NULL;
	info->visual = 0;
	info->map_list = NULL;
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
	get_list_from_map(info);
	write_player_in_map(info);
	ft_printf("\033[2J");
	cycle(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
