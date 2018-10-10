/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 15:46:54 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		zjmp(t_global *info, t_process *process)
{
	if (!process->carry)
		increase_position(process, process->curr_op.param[0] - process->curr_pos + process->start_pos);
	else
		return ;
	if (info)
		return ;
}
