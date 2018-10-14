/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:37:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/14 12:33:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_global *info, t_process *process)
{
	if (info && process){}
	/*t_param	param;

	param.iparam0 = 0;
	param.iparam1 = 0;
	param.iparam2 = 0;
	param.sparam0 = 0;
	param.sparam1 = 0;
	param.sparam2 = 0;
	if (get_param_value(info, process, 0, &param.iparam0))
		return ;
	if (process->type_param[1] == T_IND)
		param.sparam1 = process->curr_op.param[1];
	else if (process->type_param[1] == T_DIR)
		param.sparam1 = process->curr_op.param[1];
	else if (get_param_value(info, process, 1, &param.iparam1))
		return ;
	if (process->type_param[2] == T_DIR)
		param.sparam2 = process->curr_op.param[2];
	else if (get_param_value(info, process, 2, &param.iparam2))
		return ;

	ft_printf("param1 %d\n", param.sparam1);
	ft_printf("param2 %d\n", param.sparam2);
	ft_printf("pc %d\n", process->pc - get_size_param(process));
	ft_printf("pos %d\n", (param.sparam1 + param.sparam2));
	ft_printf("res %d\n", ((param.sparam1 + param.sparam2) % IDX_MOD) + process->pc - get_size_param(process));
	write_at_position(info->map, process, ((param.sparam1 + param.sparam2) % IDX_MOD) + process->pc - get_size_param(process), param.iparam0);*/
}
