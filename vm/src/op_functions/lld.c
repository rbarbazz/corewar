/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:37:54 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 14:51:28 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lld(t_global *info, t_process *process)
{
	char			*tmp;
	unsigned int	value;

	if (process->type_param[0] == T_IND)
	{
		tmp = get_value_at_position(info->map, process->curr_op.param[0], IND_SIZE);
		value = tab_to_int(tmp);
		ft_strdel(&tmp);
		process->reg[process->curr_op.param[1] - 1] = value;
	}
	else if (process->type_param[0] == T_DIR)
		process->reg[process->curr_op.param[1] - 1] = process->curr_op.param[0];
	if (!(process->reg[process->curr_op.param[1] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
