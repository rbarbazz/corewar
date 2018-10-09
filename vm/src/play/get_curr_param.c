/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:30:07 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 15:25:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	match_param(int type, int i, t_process *process)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (g_op_tab[j].opcode == process->curr_op.opcode)
		{
			if ((g_op_tab[j].param[i] | type) !=  g_op_tab[j].param[i])
				process->valid_ocp = 0;
		}
		j++;
	}
}

static int	parse_ocp(char ocp, int i)
{
	int	ret;

	ret = 0;
	if (!i)
		ret = (ocp & 192) >> 6;
	else if (i == 1)
		ret = (ocp & 48) >> 4;
	else if (i == 2)
		ret = (ocp & 12) >> 2;
	return (ret);
}

static void	without_ocp(t_global *info, t_process *process)
{
	char	*param;
	int		size;

	if (process->curr_op.opcode == 1)
		size = 4;
	else
		size = 2;
	param = get_value_at_position(info->map, process->position + 1, size);
	param = mem_rev(param, size);
	process->curr_op.param[0] = tab_to_int(param);
	process->curr_op.param[1] = 0;
	process->curr_op.param[2] = 0;
	increase_position(process, size);
}

static void	with_ocp(t_global *info, t_process *process, char ocp)
{
	int	i;
	int	type;

	i = 0;
	process->pc++;
	if (info){}
	while (i < process->curr_op.nb_param)
	{
		type = parse_ocp(ocp, i);
		match_param(type, i, process);
		i++;
	}
}

void	get_op_param(t_global *info, t_process *process, char ocp)
{
	process->pc++;
	if (process->curr_op.has_ocp)
		with_ocp(info, process, ocp);
	else
		without_ocp(info, process);
}