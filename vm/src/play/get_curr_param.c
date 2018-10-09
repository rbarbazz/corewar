/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:30:07 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 12:22:45 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	without_ocp(t_global *info, t_process *process)
{
	char	*param;
	int		size;

	if (process->curr_op.opcode == 1)
		size = 4;
	else
		size = 2;
	param = get_value_at_position(info->map, process->position + 1, size);
	param = mem_rev(param, size);
	xxd(param, 4, size);
	process->curr_op.param[0] = tab_to_int(param);
	process->curr_op.param[1] = 0;
	process->curr_op.param[2] = 0;
	ft_printf("%u\n", process->curr_op.param[0]);
	increase_position(process, size);
}

static void	with_ocp(void)
{

}

void	get_op_param(t_global *info, t_process *process, char ocp)
{
	ocp = 0;
	if (process->curr_op.has_ocp)
		with_ocp();
	else
		without_ocp(info, process);
}