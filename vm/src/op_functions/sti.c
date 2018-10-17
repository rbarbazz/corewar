/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:37:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/17 15:46:16 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_global *info, t_process *process)
{
	int		param0;
	int		param1;
	int		param2;
	short	param_sum;

	param0 = 0;
	param1 = 0;
	param2 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (get_param_value(info, process, 2, &param2))
		return ;
	param_sum = (short)(param1 + param2) % IDX_MOD;
	if (param_sum < 0)
		param_sum = MEM_SIZE + param_sum;
	if (info->debug)
	{
		ft_printf("P	%d |	sti r%d %d %d\n", process->process_nb, process->curr_op.param[0], param1, param2);
		ft_printf("	-> store to %hd + %hd = %d", param1, param2, param1 + param2);
		ft_printf(" (with pc and mod %hd)\n", (param_sum + process->op_pos) % MEM_SIZE);
	}
	write_at_position(info->map, process, param_sum + process->op_pos, param0);
	if (!param_sum)
		process->carry = 1;
	else
		process->carry = 0;
}
