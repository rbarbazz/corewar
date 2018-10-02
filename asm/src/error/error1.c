/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:37:19 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/02 15:42:33 by rbarbazz         ###   ########.fr       */
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
