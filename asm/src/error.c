/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:50:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/13 17:51:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_parse(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_printf("Parsing error near line %d col %d\n", champ->line, champ->col);
}

void	error_usage(char *prog_name)
{
	ft_printf("Usage: %s <sourcefile.s>\n", prog_name);
	exit(EXIT_FAILURE);
}

void	error_cmd_length(char *cmd, int max_length)
{
	ft_printf("Champion %s too long (Max length %d)\n", cmd + 1, max_length);
	exit_fail();
}