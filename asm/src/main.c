/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 12:07:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	display_usage(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n    -a : Instead of creating a \
.cor file, outputs a stripped and annotated version of the code to the \
standard output\n", prog_name);
	return (EXIT_FAILURE);
}

static char	*check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (NULL);
	if (argc == 3 && ft_strcmp(argv[1], "-a") != 0)
		return (NULL);
	return (argv[argc - 1]);
}

int	main(int argc, char **argv)
{
	t_sfile	*sfile;
	char	*filename;

	sfile = NULL;
	if (!(filename = check_args(argc, argv)))
		return (display_usage(argv[0]));
	store_sfile(filename, &sfile);
	return (EXIT_SUCCESS);
}