/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:23:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/12 19:56:35 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_global(t_global *info, char *prog_name)
{
	info->prog_name = prog_name;
	info->process_head = NULL;
	info->process_tail = NULL;
	info->process_count = 0;
	info->player = NULL;
	info->player_count = 0;
	info->map = NULL;
	info->clock.cycle = 0;
	info->clock.cycle_to_die = CYCLE_TO_DIE;
	info->clock.current_cycle = 0;
	info->clock.dump = 0;
	info->visual = 0;
	info->dump = 0;
	info->speed = SPEED_DEF;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}
