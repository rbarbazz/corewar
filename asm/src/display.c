/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:18:22 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 18:13:59 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_usage(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n    -a : Instead of creating a \
.cor file, outputs a stripped and annotated version of the code to the \
standard output\n", prog_name);
	exit(EXIT_FAILURE);
}

void	display_champ(t_asm *champ)
{
	t_sfile	*tmp;

	tmp = champ->sfile;
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Name : \"%s\"\n", champ->header->prog_name);
	while (tmp)
	{
		if (tmp->line && tmp->line[0])
			ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}