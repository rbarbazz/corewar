/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:26:08 by msamak            #+#    #+#             */
/*   Updated: 2018/10/03 14:14:58 by msamak           ###   ########.fr       */
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

int						check_end_file(t_player *new, char *file)
{
	int i;

	i = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + new->command_size;
	while (i < FILE_LEN_MAX)
	{
		if (file[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

static t_player			*assignate_value(char *file)
{
	t_player	*new;
	char		*command_size;

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
	if (!(new->command = ft_strndup(file + 16 + PROG_NAME_LENGTH + COMMENT_LENGTH, new->command_size)))
		exit_corewar(MALLOC_ERROR);
	if (check_end_file(new, file) == 1)
		exit_corewar(COMMAND_LENGTH_NOT_CORRESPOND);
	return(new);
}

int						init_player(t_global *info, char *file)
{
	t_player	*tmp;
	t_player	*new;

	tmp = info->player;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = assignate_value(file);
	if (!tmp)
		info->player = new;
	else
		tmp->next = new;
	return (0);
}
