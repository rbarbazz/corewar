/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:26:08 by msamak            #+#    #+#             */
/*   Updated: 2018/10/02 19:30:12 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int				tab_to_int(char *str)
{
	int res;

	res = 0;
	res = res | str[3];
	res = res | (str[2] << 8);
	res = res | (str[1] << 16);
	res = res | (str[0] << 24);
	return (res);
}

int						init_player(t_global *info, char *file)
{
	t_player	*new;
	t_player	*tmp;
	char		*command_size;

	tmp = info->player;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_player*)ft_memalloc(sizeof(t_player))))
		exit_corewar(MALLOC_ERROR);
	if (!(new->name = ft_strndup(file + 4, PROG_NAME_LENGTH)))
		exit_corewar(MALLOC_ERROR);
	if (!(command_size = ft_strndup(file + 8 + PROG_NAME_LENGTH, 4)))
		exit_corewar(MALLOC_ERROR);
	new->command_size = tab_to_int(command_size);
	ft_strdel(&command_size);
	if (!(new->comment = ft_strndup(file + 12 + PROG_NAME_LENGTH, COMMENT_LENGTH)))
		exit_corewar(MALLOC_ERROR);
	if (!tmp)
		info->player = new;
	else
		tmp->next = new;
	return (0);
}
