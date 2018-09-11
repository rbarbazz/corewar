/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:50:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 19:03:43 by rbarbazz         ###   ########.fr       */
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
	ft_printf("Usage: %s [-a] <sourcefile.s>\n    -a : Instead of creating a \
.cor file, outputs a stripped and annotated version of the code to the \
standard output\n", prog_name);
	exit(EXIT_FAILURE);
}

void	error_prog_name_length(void)
{
	ft_printf("Champion name too long (Max length %d)\n", PROG_NAME_LENGTH);
	exit_fail();
}
