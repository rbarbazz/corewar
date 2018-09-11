/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 17:00:09 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_name_cmd(t_asm *champ)
{
	unsigned long	i;

	i = 0;
	skip_non_print(champ);
	while (champ->sfile && champ->sfile[champ->i] &&\
	NAME_CMD_STRING[i] == champ->sfile[champ->i])
	{
		i++;
		move_index(champ);
	}
	if (i != ft_strlen(NAME_CMD_STRING))
		return (1);
	return (0);
}

int	parser(t_asm *champ)
{
	if (check_name_cmd(champ))
	{
		display_error_parse();
		return (1);
	}
	return (0);
}