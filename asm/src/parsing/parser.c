/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/13 14:14:03 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_header(t_asm *champ)
{
	if (check_cmd(champ, NAME_CMD_STRING) || check_cmd_value(champ,\
	PROG_NAME_LENGTH, champ->header->prog_name,	NAME_CMD_STRING))
	{
		error_parse();
		return (1);
	}
	skip_space(champ);
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
	{
		error_parse();
		return (1);
	}
	move_index(champ);
	if (check_cmd(champ, COMMENT_CMD_STRING) ||	check_cmd_value(champ,\
	COMMENT_LENGTH, champ->header->comment,	COMMENT_CMD_STRING))
	{
		error_parse();
		return (1);
	}
	return (0);
}

int			parser(t_asm *champ)
{
	if (parse_header(champ))
		return (1);
	skip_non_print(champ);
//	if (parse_instructions())
	return (0);
}
