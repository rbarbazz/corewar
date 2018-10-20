/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:37:27 by msamak            #+#    #+#             */
/*   Updated: 2018/10/19 11:24:32 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	free_middle_process(t_process *process)
{
	process->prev->next = process->next;
	process->next->prev = process->prev;
}

static void	free_last_process(t_global *info, t_process *process)
{
	if (process->prev)
	{
		info->process_tail = process->prev;
		process->prev->next = NULL;
	}
}

static void	free_first_process(t_global *info, t_process *process)
{
	if (process->next)
	{
		info->process_head = process->next;
		process->next->prev = NULL;
	}
	else
	{
		info->process_head = NULL;
		info->process_tail = NULL;
	}
}

void		kill_process(t_global *info, t_process *process)
{
	if (!process)
		return ;
	if (!process->prev)
		free_first_process(info, process);
	else if (!process->next)
		free_last_process(info, process);
	else
		free_middle_process(process);
	ft_memdel((void **)&process);
	info->process_count--;
}
