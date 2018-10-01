/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:50:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 10:38:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_overflow(void)
{
	ft_printf("Overflow value\n");
	error_parse();
}

void	error_parse(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_printf("Parsing error near line %d col %d\n", champ->line, champ->col);
	free_asm();
	exit(PARSE_ERR);
}

void	error_cmd(char *cmd)
{
	ft_printf("Parsing error near command : %s\n", cmd + 1);
	free_asm();
	exit(WRONG_CMD);
}

void	error_cmd_value(char *cmd)
{
	ft_printf("Parsing error for %s value\n", cmd + 1);
	free_asm();
	exit(WRONG_CMD_VALUE);
}

void	error_cmd_length(char *cmd, int max_length)
{
	ft_printf("Champion %s too long (Max length %d)\n", cmd + 1, max_length);
	free_asm();
	exit(CMD_TOO_BIG);
}
