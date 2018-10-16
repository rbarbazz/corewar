/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:22:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/16 13:01:06 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ldi(t_global *info, t_process *process)
{
	int		param0;
	int		param1;
	char	*value;

	param0 = 0;
	param1 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (check_reg(info, process, 2))
		return ;
	if (process->type_param[0] == T_IND)
		param0 %= IDX_MOD;
	if (process->type_param[1] == T_IND)
		param1 %= IDX_MOD;
	//ft_printf("	ldi r%d -> %d %d\n", process->curr_op.param[0], param1, param2);
	//ft_printf("	-> store to %d + %d = %d", param1, param2, param1 + param2);
	//ft_printf(" (with pc and mod %d)\n", (((param1 + param2) % IDX_MOD) + process->op_pos));
	value = get_value_at_position(info->map, ((param0 + param1) % IDX_MOD) + process->op_pos, 4);
	process->reg[process->curr_op.param[2] - 1] = tab_to_int(value);
	ft_strdel(&value);
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
