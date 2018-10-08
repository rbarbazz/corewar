/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:29:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 18:01:30 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** iterates on the op tab to find the coresponding opcode
** stores the number of cycles required
** if no match -> return -1
** *****************************************************************************
*/

int		get_cycle_from_op(int op, t_process *process)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (g_op_tab[i].opcode == op)
		{
			process->ocp = g_op_tab[i].has_ocp;
			return (g_op_tab[i].cycle);
		}
		i++;
	}
	return (-1);
}

/*
** *****************************************************************************
** gets from 1 to 4 bytes from a position on the map
** *****************************************************************************
*/

char	*get_value_at_position(t_map *map, int position, int size)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(4)))
		exit_corewar(MALLOC_ERROR);
	while (map && position)
	{
		map = map->next;
		position--;
	}
	i = 3;
	while (map && size)
	{
		ret[i--] = map->c;
		map = map->next;
		size--;
	}
	return (ret);
}

/*
** *****************************************************************************
** main function to manage the processes
** *****************************************************************************
*/

void	check_process(t_global *info)
{
	t_process	*tmp_proc;

	tmp_proc = info->process_tail;
	while (tmp_proc)
	{
		if (tmp_proc->cycle_left < 0)
			get_op(info, tmp_proc);
		else if (tmp_proc->cycle_left - 1 > 0)
			tmp_proc->cycle_left--;
		else
		{
			tmp_proc->cycle_left = -1;
			//for now only increments position +1
			increase_position(tmp_proc);
			//do_op()
		}
		tmp_proc = tmp_proc->prev;
	}
}
