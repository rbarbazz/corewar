/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:18:22 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 18:51:08 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_champ(t_asm *champ)
{
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Name : \"%s\"\n", champ->header->prog_name);
	ft_printf("Comment : \"%s\"\n", champ->header->comment);
//	ft_printf("%s", champ->sfile);
}
