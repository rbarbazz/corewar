/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 11:33:59 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	display_usage(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n    -a : Instead of creating a\
	 .cor file, outputs a stripped and annotated version of the code to the\
	  standard output\n", prog_name);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (display_usage(argv[0]));
	return (EXIT_SUCCESS);
}