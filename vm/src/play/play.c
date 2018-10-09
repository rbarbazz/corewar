/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:00:00 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 16:23:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** where the game takes place
** until cycle returns, the game is on
** *****************************************************************************
*/

int	play(t_global *info)
{
	info->process_count = info->player_count;
	create_initial_process(info);
	if (!info->visual)
		display_intro(info);
	while (!cycle(info))
	{
		check_process(info);
		update_map(info);
		if (info->visual)
			print_map(info);
		//Debug
		//sleep(1);
	}
	return (0);
}
