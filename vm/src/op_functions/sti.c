/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:37:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/14 17:57:37 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_global *info, t_process *process)
{
	if (info || process) 
	{;}
	/*
	int	param1;
	int	param2;

	param1 = 0;
	param2 = 0;
	if (check_reg(info, process, process->curr_op.param[0]))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (get_param_value(info, process, 2, &param2))
		return ;
	ft_printf("param1 %d\n", param1);
	ft_printf("param2 %d\n", param2);
	ft_printf("pc %d\n", process->pc - get_size_param(process));
	ft_printf("pos %d\n", (param1 + param2));
	ft_printf("res %d\n", ((param1 + param2) % IDX_MOD) + process->pc - get_size_param(process));
	write_at_position(info->map, process, ((param1 + param2) % IDX_MOD) + process->pc - get_size_param(process), param0);
	*/
}
