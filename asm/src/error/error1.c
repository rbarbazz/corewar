/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:37:19 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/17 13:49:30 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_size(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_printf("Champion is too big, the max is %u bytes\n", CHAMP_MAX_SIZE);
	ft_printf("Check near line %i col %i\n", champ->line, champ->col);
	free_asm();
	exit(CHAMP_TOO_BIG);
}

void	error_separator(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_printf("Parsing error near line %d col %d", champ->line, champ->col);
	ft_printf(" : missing or wrong separator\n");
	free_asm();
	exit(ERR_SEP);
}

void	error_reg(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_printf("Parsing error near line %d col %d", champ->line, champ->col);
	ft_printf(" : wrong register number\n");
	free_asm();
	exit(WRONG_REG);
}

void	error_no_instr(void)
{
	ft_printf("No instructions provided\n");
	free_asm();
	exit(NO_INSTR);
}
