/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:30:05 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/12 14:26:33 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** check the syntax of the expected instructions
** store them into the header
*/

int	check_instruction(t_asm *champ, char *instr)
{
	unsigned long	i;

	i = 0;
	skip_non_print(champ);
	while (champ->sfile && champ->sfile[champ->i] &&\
	instr[i] == champ->sfile[champ->i])
	{
		i++;
		move_index(champ);
	}
	if (i != ft_strlen(instr))
		return (1);
	return (0);
}

/*
** check the syntax of the expected instruction values
** store them into the header
*/

int	check_instruction_value(t_asm *champ, int max_length, char *instr,\
char *cmd)
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
		if (i > max_length)
			error_instruction_length(cmd, max_length);
		instr[i] = champ->sfile[champ->i];
		i++;
		move_index(champ);
	}
	if (!champ->sfile || !champ->sfile[champ->i])
		return (1);
	move_index(champ);
	return (0);
}
