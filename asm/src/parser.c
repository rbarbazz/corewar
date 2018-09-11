/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 11:07:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_name(void)
{
	return (0);
}

int	parser(t_asm *champ)
{
	champ->line_nb++;
	if (get_name())
	{
		display_error_parse();
		return (1);
	}
	return (0);
}