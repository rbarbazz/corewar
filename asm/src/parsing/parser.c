/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/03 17:03:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_header(t_asm *champ)
{
	check_cmd(champ, NAME_CMD_STRING);
	check_cmd_value(champ, PROG_NAME_LENGTH, NAME_CMD_STRING,\
	champ->header->prog_name);
	skip_space();
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
		error_cmd_value(NAME_CMD_STRING);
	move_index();
	check_cmd(champ, COMMENT_CMD_STRING);
	check_cmd_value(champ, COMMENT_LENGTH, COMMENT_CMD_STRING,\
	champ->header->comment);
}

int			parser(t_asm *champ)
{
	parse_header(champ);
	skip_non_print();
	while (champ->sfile && champ->sfile[champ->i])
	{
		look_for_label(champ);
		look_for_op(champ);
	}
	check_label_pos(champ);
	return (0);
}
