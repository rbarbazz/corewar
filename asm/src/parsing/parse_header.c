/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:30:05 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/24 15:15:43 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** check the syntax of the expected instructions
** store them into the header
*/

void	check_cmd(t_asm *champ, char *cmd)
{
	unsigned long	i;

	i = 0;
	skip_non_print();
	while (champ->sfile && champ->sfile[champ->i] &&\
	cmd[i] == champ->sfile[champ->i])
	{
		i++;
		move_index();
	}
	if (i != ft_strlen(cmd))
		error_cmd(cmd);
}

/*
** check the syntax of the expected instruction values
** store them into the header
*/

void	check_cmd_value(t_asm *champ, int max_length, char *cmd, char *value)
{
	int	i;

	i = 0;
	skip_space();
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\"')
		error_cmd_value(cmd);
	move_index();
	while (champ->sfile && champ->sfile[champ->i] &&\
	champ->sfile[champ->i] != '\"')
	{
		if (i > max_length)
			error_cmd_length(cmd, max_length);
		value[i] = champ->sfile[champ->i];
		i++;
		move_index();
	}
	if (!champ->sfile || !champ->sfile[champ->i])
		error_cmd_value(cmd);
	move_index();
}
