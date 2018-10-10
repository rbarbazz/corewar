/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:28:53 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 14:50:31 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_reg(t_global *info, t_process *process)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (process->curr_op.param[i] > 15)
		{
			ft_dprintf(STDERR_FILENO, "Registre inexistant : %u\n", process->curr_op.param[i]);
			kill_process(info, process);
			return (1);
		}
		i++;
	}
	return (0);
}

void		add(t_global *info, t_process *process)
{
	if (check_reg(info, process))
		return ;
	process->reg[process->curr_op.param[2] - 1] = process->reg[process->curr_op.param[0] - 1] + process->reg[process->curr_op.param[1] - 1];
	if (!(process->reg[process->curr_op.param[2] - 1]))
		process->carry = 1;
	else
		process->carry = 0;
}
