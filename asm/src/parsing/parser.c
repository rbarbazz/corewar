/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/12 14:30:35 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_instructions(t_asm *champ)
{
	if (check_instruction(champ, NAME_CMD_STRING) ||\
	check_instruction_value(champ, PROG_NAME_LENGTH, champ->header->prog_name,\
	NAME_CMD_STRING))
	{
		error_parse();
		return (1);
	}
	skip_space(champ);
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
		return (1);
	move_index(champ);
	if (check_instruction(champ, COMMENT_CMD_STRING) ||\
	check_instruction_value(champ, COMMENT_LENGTH, champ->header->comment,\
	COMMENT_CMD_STRING))
	{
		error_parse();
		return (1);
	}
	return (0);
}

int	parser(t_asm *champ)
{
	if (parse_instructions(champ))
		return (1);
	return (0);
}
