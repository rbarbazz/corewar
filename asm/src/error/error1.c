/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:37:19 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/22 12:14:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_size(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_dprintf(STDERR_FILENO, "Champion is too big, the max is %u bytes\n",\
	CHAMP_MAX_SIZE);
	ft_dprintf(STDERR_FILENO, "Check near line %i col %i\n", champ->line,\
	champ->col);
	free_asm();
	exit(CHAMP_TOO_BIG);
}

void	error_separator(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_dprintf(STDERR_FILENO, "Parsing error near line %d col %d",\
	champ->line, champ->col);
	ft_dprintf(STDERR_FILENO, " : missing or wrong separator\n");
	free_asm();
	exit(ERR_SEP);
}

void	error_reg(void)
{
	t_asm	*champ;

	champ = get_champ();
	ft_dprintf(STDERR_FILENO, "Parsing error near line %d col %d",\
	champ->line, champ->col);
	ft_dprintf(STDERR_FILENO, " : wrong register number\n");
	free_asm();
	exit(WRONG_REG);
}

void	error_no_instr(void)
{
	ft_dprintf(STDERR_FILENO, "No instructions provided\n");
	free_asm();
	exit(NO_INSTR);
}
