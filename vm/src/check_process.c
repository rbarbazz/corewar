/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:29:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/05 18:38:03 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//static void	get_op(t_global *info)
//{
//}

void		check_process(t_global *info)
{
	t_process	*tmp_proc;

	tmp_proc = info->process_tail;
	while (tmp_proc)
	{
		if (tmp_proc->cycle_left < 0)
		{}	//parse_op
		else if (tmp_proc->cycle_left > 0)
			tmp_proc->cycle_left--;
		else
		{
			tmp_proc->cycle_left = -1;
			//do_op()
		}
		tmp_proc = tmp_proc->prev;
	}
}
