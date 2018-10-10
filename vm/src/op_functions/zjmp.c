/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 17:16:07 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		zjmp(t_global *info, t_process *process)
{
	ft_printf("currpos %u\n", process->curr_pos);
	if (process->carry)
		increase_position(process, process->curr_pos - process->curr_op.param[0]);
	else
		return ;
	if (info)
		return ;
}
