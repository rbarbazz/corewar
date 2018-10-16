/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 14:05:12 by rbarbazz         ###   ########.fr       */
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
	int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (info->debug)
		ft_printf("P	%d |	zjmp %hd", process->process_nb, param0);
	if (process->carry)
	{
		if (info->debug)
			ft_printf(" OK");
		increase_position(process, param0 - (process->curr_pos - process->op_pos));
	}
	else
		return ;
	if (info->debug)
		ft_printf("\n");
}
