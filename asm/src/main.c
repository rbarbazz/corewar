/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 19:10:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_champ(t_asm *champ)
{
	static t_header	header;

	champ->sfile = NULL;
	champ->header = &header;
	ft_bzero(champ->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(champ->header->comment, COMMENT_LENGTH + 1);
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
	if (parser(champ))
		exit_fail();
	if (argc == 3)
		display_champ(champ);
	free_asm();
	return (EXIT_SUCCESS);
}