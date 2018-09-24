/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/24 15:56:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_champ(t_asm *champ)
{
	static t_header	header;

	champ->sfile = NULL;
	champ->header = &header;
	champ->header->magic = COREWAR_EXEC_MAGIC;
	ft_bzero(champ->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(champ->header->comment, COMMENT_LENGTH + 1);
	champ->line = 1;
	champ->col = 1;
	champ->i = 0;
	ft_bzero(champ->cor_file, CHAMP_MAX_SIZE + 1);
}

t_asm	*get_champ(void)
{
	static t_asm	champ;

	return (&champ);
}

int		main(int argc, char **argv)
{
	t_asm	*champ;

	champ = get_champ();
	init_champ(champ);
	if (!(champ->filename = check_args(argc, argv)))
		error_usage(argv[0]);
	if (!(champ->sfile = store_sfile(champ->filename)))
		error_empty();
	if (parser(champ))
		error_parse();
	write_to_cor(champ);
	free_asm();
	return (EXIT_SUCCESS);
}

/*
** Todo :
*/
