/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:37:27 by msamak            #+#    #+#             */
/*   Updated: 2018/10/10 14:27:15 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		kill_process(t_global *info, t_process *process)
{
	if (process->prev)
		process->prev->next = process->next;
	else if (!process->prev)
	{
		if (process->next)
			info->process_head = process->next;
		else
		{
			info->process_head = NULL;
			info->process_tail = NULL;
		}
	}
	if (process->next)
		process->next->prev = process->prev;
	else if (!process->next)
	{
		if (process->prev)
			info->process_tail = process->prev;
		else
		{
			info->process_head = NULL;
			info->process_tail = NULL;
		}
	}
	ft_memdel((void **)&process);
	info->process_count--;
}
