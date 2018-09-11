/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:30:05 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 19:29:38 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		if (i > PROG_NAME_LENGTH)
			error_prog_name_length();
		champ->header->prog_name[i] = champ->sfile[champ->i];
		i++;
		move_index(champ);
	}
	if (!champ->sfile || !champ->sfile[champ->i])
		return (1);
	move_index(champ);
	return (0);
}
