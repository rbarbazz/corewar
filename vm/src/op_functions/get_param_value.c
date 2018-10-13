/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:47:32 by msamak            #+#    #+#             */
/*   Updated: 2018/10/14 00:56:54 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	check_reg(t_global *info, t_process *process, int param)
{
	if (process->curr_op.param[param] > 15)
	{
		ft_dprintf(STDERR_FILENO, "Registre inexistant : %u\n",\
		process->curr_op.param[param]);
		kill_process(info, process);
		return (1);
	}
	return (0);
}

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
		tmp = get_value_at_position(info->map, process->curr_op.param[i], 4);
		*param = tab_to_int(tmp);
		ft_strdel(&tmp);
	}
	else if (process->type_param[i] == T_DIR)
	{
		if (!process->curr_op.nb_or_address)
			*param = process->curr_op.param[i];
		else
			*param = process->curr_op.param[i] + process->pc;
	}
	return (0);
}
