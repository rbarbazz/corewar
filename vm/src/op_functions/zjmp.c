/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:53:16 by msamak            #+#    #+#             */
/*   Updated: 2018/10/16 11:40:43 by rbarbazz         ###   ########.fr       */
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
	ft_printf("	zjmp %hd", param0);
	if (process->carry)
	{
		ft_printf(" OK");
		increase_position(process, param0 - 3);
	}
	else
		return ;
	ft_printf("\n");
}
