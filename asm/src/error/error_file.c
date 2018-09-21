/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:35:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/21 18:42:12 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_usage(char *prog_name)
{
	ft_printf("Usage: %s <sourcefile.s>\n", prog_name);
	exit(WRONG_USAGE);
}

void	error_empty(void)
{
	ft_printf("Input file empty\n");
	free_asm();
	exit(FILE_EMPTY);
}
