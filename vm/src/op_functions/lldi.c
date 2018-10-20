/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:24:38 by msamak            #+#    #+#             */
/*   Updated: 2018/10/19 11:26:24 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lldi(t_global *info, t_process *process)
{
	int		param0;
	int		param1;
	char	*value;
	short	param_sum;

	param0 = 0;
	param1 = 0;
	if (get_param_value(info, process, 0, &param0)\
	|| get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	param_sum = (short)param0 + (short)param1;
	value = get_value_at_position(info->map, param_sum + process->op_pos, 4);
	process->reg[process->curr_op.param[2] - 1] = tab_to_int(value);
	ft_strdel(&value);
	if (info->debug)
	{
		ft_printf("P%5d | lldi %hd %hd r%d\n", process->process_nb, param0,\
		param1, process->curr_op.param[2]);
		ft_printf("       | -> load from %hd + %hd = %hd", param0, param1,\
		param0 + param1);
		ft_printf(" (with pc and mod %hd)\n", param_sum + process->op_pos);
	}
	ft_carry(process, process->reg[process->curr_op.param[2] - 1]);
}
