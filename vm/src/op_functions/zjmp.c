/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 17:53:00 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** jumps from the opcode
** not from curr_pos which at this moment is after the params
** *****************************************************************************
*/

void		zjmp(t_global *info, t_process *process)
{
	if (process->carry)
		increase_position(process, process->curr_op.param[0] - 3);
	else
		return ;
	if (info)
		return ;
}
