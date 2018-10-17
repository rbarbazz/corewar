/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:22:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/17 11:53:09 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ldi(t_global *info, t_process *process)
{
	int		param0;
	int		param1;
	char	*value;
	short	param_sum;

	param0 = 0;
	param1 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	param_sum = (short)param0 + (short)param1;
	value = get_value_at_position(info->map, param_sum % IDX_MOD + process->op_pos, 4);
	process->reg[process->curr_op.param[2] - 1] = tab_to_int(value);
	ft_strdel(&value);
	if (info->debug)
	{
		ft_printf("P	%d |	ldi %hd %hd r%d\n", process->process_nb, param0, param1, process->curr_op.param[2]);
		ft_printf("	-> load from %hd + %hd = %hd", param0 , param1, param0 + param1);
		ft_printf(" (with pc and mod %hd)\n",((param_sum) % IDX_MOD + process->op_pos));
	}
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
