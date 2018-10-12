/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:32:33 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/12 18:32:45 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	st(t_global *info, t_process *process)
{
	unsigned int	param0;
	unsigned int	param1;

	param0 = 0;
	param1 = process->curr_op.param[1];
	if (get_param_value(info, process, 0, &param0))
		return ;
	ft_printf("param1 avant idx: %u\n", param1);
	param1 %= IDX_MOD;
	ft_printf("param0 : %u\n", param0);
	ft_printf("param1 : %u\n", param1);
	if (process->type_param[1] == T_REG)
		process->reg[process->curr_op.param[1] - 1] = param0;
	else
		write_at_position(info->map, process, param1, param0);
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
