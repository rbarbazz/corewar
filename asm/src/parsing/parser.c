/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 19:30:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	parser(t_asm *champ)
{
	if (check_instruction(champ, NAME_CMD_STRING) || check_name(champ))
	{
		error_parse();
		return (1);
	}
	skip_space(champ);
	//error comment token to specify
	if (!champ->sfile || !champ->sfile[champ->i] ||\
	champ->sfile[champ->i] != '\n')
		return (1);
	move_index(champ);
	if (check_instruction(champ, COMMENT_CMD_STRING))
	{
		error_parse();
		return (1);
	}
	return (0);
}
