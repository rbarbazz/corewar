/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:36:34 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/09 18:45:56 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_intro(t_global *info)
{
	t_player	*tmp_p;

	tmp_p = info->player;
	ft_printf("Introducing contestants...\n");
	while (tmp_p)
	{
		ft_printf("* Player %d, ", tmp_p->player);
		ft_printf("weighing %u bytes, ", tmp_p->prog_size);
		ft_printf("\"%s\" (\"%s\") !\n", tmp_p->name, tmp_p->comment);
		tmp_p = tmp_p->next;
	}
}
