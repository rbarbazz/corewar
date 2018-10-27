/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:50:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/27 13:22:12 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_lab(t_lab_pos *lab_pos)
{
	ft_dprintf(STDERR_FILENO, "Parsing error near line %d col %d",\
		lab_pos->line, lab_pos->col);
	ft_dprintf(STDERR_FILENO, " : label not defined\n");
	free_asm();
	exit(LAB_NOT_DEFINED);
}

void	error_parse(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_dprintf(STDERR_FILENO, "Parsing error near line %d col %d\n",\
		champ->line, champ->col);
	free_asm();
	exit(PARSE_ERR);
}

void	error_cmd(char *cmd)
{
	ft_dprintf(STDERR_FILENO, "Parsing error near command : %s\n", cmd + 1);
	free_asm();
	exit(WRONG_CMD);
}

void	error_cmd_value(char *cmd)
{
	ft_dprintf(STDERR_FILENO, "Parsing error for %s value\n", cmd + 1);
	free_asm();
	exit(WRONG_CMD_VALUE);
}

void	error_cmd_length(char *cmd, int max_length)
{
	ft_dprintf(STDERR_FILENO, "Champion %s too long (Max length %d)\n",\
		cmd + 1, max_length);
	free_asm();
	exit(CMD_TOO_BIG);
}
