/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:32:26 by msamak            #+#    #+#             */
/*   Updated: 2018/10/19 11:47:16 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_player(void)
{
	t_global	*info;
	t_player	*tmp;
	t_player	*save;

	info = get_global();
	tmp = info->player_head;
	while (tmp)
	{
		save = tmp->next;
		ft_strdel(&tmp->name);
		ft_strdel(&tmp->comment);
		ft_strdel(&tmp->instruction);
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

void		free_map(void)
{
	t_global	*info;
	t_map		*tmp;
	t_map		*save;
	int			i;

	i = MEM_SIZE;
	info = get_global();
	tmp = info->map;
	while (tmp && i--)
	{
		save = tmp->next;
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

void		free_process(void)
{
	t_global	*info;
	t_process	*tmp;
	t_process	*save;

	info = get_global();
	tmp = info->process_head;
	while (tmp)
	{
		save = tmp->next;
		ft_memdel((void **)&tmp);
		tmp = save;
	}
}

/*
** *****************************************************************************
** no risk of double free as the function only frees if !NULL
** *****************************************************************************
*/

void		free_all(void)
{
	free_player();
	free_map();
	free_process();
}
