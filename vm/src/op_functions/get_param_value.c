/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:47:32 by msamak            #+#    #+#             */
/*   Updated: 2018/10/18 15:43:36 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	check_reg(t_global *info, t_process *process, int param)
{
	if (process->curr_op.param[param] > 16 || !process->curr_op.param[param])
	{
		if (!info->visual && !info->debug)
			ft_dprintf(STDERR_FILENO, "Registre inexistant : %u\n",\
		process->curr_op.param[param]);
		return (1);
	}
	return (0);
}

/*
** *****************************************************************************
** case REG : gets the value in a reg (4 bytes)
** case IND : gets the value at the position specified from op_pos (4 bytes)
** case DIR : gets the value as it is (4 bytes)
** *****************************************************************************
*/

int	get_param_value(t_global *info, t_process *process, int i, int *param)
{
	char	*tmp;

	if (process->type_param[i] == T_REG)
	{
		if (check_reg(info, process, i))
			return (1);
		*param = process->reg[process->curr_op.param[i] - 1];
	}
	else if (process->type_param[i] == T_IND)
	{
		tmp = get_value_at_position(info->map, process->op_pos +\
		process->curr_op.param[i], 4);
		*param = tab_to_int(tmp);
		ft_strdel(&tmp);
	}
	else if (process->type_param[i] == T_DIR)
		*param = process->curr_op.param[i];
	return (0);
}
