/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 22:37:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/14 17:36:13 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_global *info, t_process *process)
{
	int	param0;
	int	param1;
	int	param2;

	param0 = 0;
	param1 = 0;
	param2 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (get_param_value(info, process, 1, &param1))
		return ;
	if (get_param_value(info, process, 2, &param2))
		return ;
//	ft_printf("param0 %d\n", param0);
//	ft_printf("param1 %d\n", param1);
//	ft_printf("param2 %d\n", param2);
//	ft_printf("res %hd\n", param1 + param2);
//	ft_printf("pos %hd\n", (((param1 + param2) % IDX_MOD) + process->op_pos));
	write_at_position(info->map, process, ((param1 + param2) % IDX_MOD) + process->op_pos, param0);
	if (!param0)
		process->carry = 1;
	else
		process->carry = 0;
}
