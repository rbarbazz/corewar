/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:30:07 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 16:51:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** check if param type found matches
** *****************************************************************************
*/

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

/*
** *****************************************************************************
** apply mask coresponding to the current param to find its type
** *****************************************************************************
*/

static int	parse_ocp(unsigned char ocp, int i)
{
	int	ret;

	ft_printf("ocp parse param: %d\n", ocp);
	ret = 0;
	if (!i)
		ret = (ocp & 192) >> 6;
	else if (i == 1)
		ret = (ocp & 48) >> 4;
	else if (i == 2)
		ret = (ocp & 12) >> 2;
	return (ret);
}

/*
** *****************************************************************************
** case no ocp : get one param
** *****************************************************************************
*/

static void	without_ocp(t_global *info, t_process *process)
{
	char	*param;
	int		size;

	if (process->curr_op.opcode == 1)
		size = 4;
	else
		size = 2;
	param = get_value_at_position(info->map, process->curr_pos, size);
	param = mem_rev(param, size);
	ft_printf("without ocp size : %d\n", size);
	process->curr_op.param[0] = tab_to_int(param);
	process->curr_op.param[1] = 0;
	process->curr_op.param[2] = 0;
	increase_position(process, size);
}

/*
** *****************************************************************************
** check the ocp and get the param according to their size
** *****************************************************************************
*/

static void	with_ocp(t_process *process, unsigned char ocp)
{
	int	i;
	int	type;

	i = 0;
	increase_position(process, 1);
	while (i < process->curr_op.nb_param)
	{
		type = parse_ocp(ocp, i);
		match_param(type, i, process);
		if (type == REG_CODE)
		{
			increase_position(process, 1);
			ft_printf("T_REG\n");
		}
		else if (type == IND_CODE)
		{
			increase_position(process, 2);
			ft_printf("T_IND\n");
		}
		else if (type == DIR_CODE && process->curr_op.nb_or_address)
		{
			increase_position(process, 2);
			ft_printf("T_DIR size 2\n");
		}
		else if (type == DIR_CODE && !process->curr_op.nb_or_address)
		{
			increase_position(process, 4);
			ft_printf("T_DIR size 4\n");
		}
		i++;
	}
}

void	get_op_param(t_global *info, t_process *process, unsigned char ocp)
{
	if (process->curr_op.has_ocp)
		with_ocp(process, ocp);
	else
		without_ocp(info, process);
	ft_printf("\n");
}