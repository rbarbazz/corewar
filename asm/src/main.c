/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 17:43:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_champ(t_asm *champ)
{
	champ->sfile = NULL;
	champ->name = NULL;
	champ->comment = NULL;
}

t_asm	*get_champ(void)
{
	static t_asm	champ;

	return (&champ);
}

int		main(int argc, char **argv)
{
	t_asm	*champ;
	char	*filename;

	champ = get_champ();
	init_champ(champ);
	if (!(filename = check_args(argc, argv)))
		display_usage(argv[0]);
	store_sfile(filename, &champ->sfile);
	if (argc == 3)
		display_sfile(champ->sfile);
	free_asm();
	return (EXIT_SUCCESS);
}