/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/03 17:28:25 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_global(t_global *info)
{
	info->process = NULL;
	info->player = NULL;
	info->visual = 0;
	info->map_list = NULL;
}

t_global	*get_global(void)
{
	static t_global info;

	return (&info);
}

int			write_player_in_map(t_global *info)
{
	t_player		*tmp;
	t_map			*tmp_map;
	unsigned int	i;
	int				j;
	int				position;

	tmp = info->player;
	tmp_map = info->map_list;
	position = (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	j = 0;
	while (tmp)
	{
		i = 0;
		while (i < tmp->command_size)
		{
			tmp_map->c = tmp->command[i];
			tmp_map->player = tmp->player;
			i++;
			j++;
			tmp_map = tmp_map->next;
		}
		while (j < position)
		{
			tmp_map = tmp_map->next;
			j++;
		}
		tmp = tmp->next;
		position = position + (ft_sqrt(MEM_SIZE) / info->player_count) * ft_sqrt(MEM_SIZE);
	}
	return (0);
}

int			init_map(t_global *info, char c)
{
	t_map	*tmp;
	t_map	*new;

	tmp = info->map_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_map*)ft_memalloc(sizeof(t_map))))
		exit_corewar(MALLOC_ERROR);
	new->c = c;
	new->player = 0;
	if (!tmp)
		info->map_list = new;
	else
		tmp->next = new;
	return (0);
}

int			get_list_from_map(t_global *info)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		init_map(info, 0);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_global	*info;

	info = get_global();
	check_args(info, argc, argv);
	get_list_from_map(info);
	write_player_in_map(info);
	print_map_list(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
