/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/24 18:19:08 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_header(t_asm *champ)
{
	check_cmd(champ, NAME_CMD_STRING);
	check_cmd_value(champ, PROG_NAME_LENGTH, NAME_CMD_STRING,\
	champ->header->prog_name);
	skip_space(champ);
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
		error_cmd_value(NAME_CMD_STRING);
	move_index(champ);
	check_cmd(champ, COMMENT_CMD_STRING);
	check_cmd_value(champ, COMMENT_LENGTH, COMMENT_CMD_STRING,\
	champ->header->comment);
}

/*static int	is_label_char(char c)
{
	int	i;

	i = 0;
	while (LABEL_CHARS && LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}
*/

int			parser(t_asm *champ)
{
	parse_header(champ);
	skip_non_print(champ);
	while (!champ->sfile || !champ->sfile[champ->i])
	{
		move_index(champ);
	}
	return (0);
}
