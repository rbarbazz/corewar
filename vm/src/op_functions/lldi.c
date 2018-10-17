/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:24:38 by msamak            #+#    #+#             */
/*   Updated: 2018/10/17 15:24:45 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lldi(t_global *info, t_process *process)
{
	int		param0;
	int		param1;
	char	*value;

	param0 = 0;
	param1 = 0;
	if (process->type_param[0] == T_IND)
		process->curr_op.param[0] %= IDX_MOD;
	if (process->type_param[1] == T_IND)
		process->curr_op.param[1] %= IDX_MOD;
	if (process->type_param[0] == T_DIR)
		process->curr_op.param[0] = (short)process->curr_op.param[0];
	if (process->type_param[1] == T_DIR)
		process->curr_op.param[1] = (short)process->curr_op.param[1];

	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	value = get_value_at_position(info->map, param0 + param1 +\
	process->op_pos, 4);
	process->reg[process->curr_op.param[2] - 1] = tab_to_int(value);
	ft_strdel(&value);
	if (info->debug)
	{
		ft_printf("P	%d |	lldi %d %d r%d\n", process->process_nb, param0, param1, process->curr_op.param[2]);
		ft_printf("	-> load from %d + %d = %d", param0, param1, param0 + param1);
		ft_printf(" (with pc %d)\n", param0 + param1 + process->op_pos);
	}
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
