/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:30:05 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 18:32:57 by rbarbazz         ###   ########.fr       */
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

int	check_name(t_asm *champ)
{
	int	i;

	i = 0;
	skip_space(champ);
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\"')
		return (1);
	move_index(champ);
	while (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] != '\"')
	{
		champ->header->prog_name[i] = champ->sfile[champ->i];
		i++;
		move_index(champ);
	}
	if (!champ->sfile || !champ->sfile[champ->i])
		return (1);
	return (0);
}
