/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/01 11:41:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Step by step asm :
** - handle format error
** - store the s file as a char* without comments
** - parse header and store it with as static variable
** - parse labels and instructions and store them on a char*
** - write the header and the rest of the file on the cor file
*/

void	init_champ(t_asm *champ)
{
	static t_header	header;

	champ->sfile = NULL;
	champ->header = &header;
	champ->header->magic = COREWAR_EXEC_MAGIC;
	ft_bzero(champ->header->prog_name, PROG_NAME_LENGTH + 1);
	champ->header->prog_size = 0;
	ft_bzero(champ->header->comment, COMMENT_LENGTH + 1);
	champ->line = 1;
	champ->col = 1;
	champ->i = 0;
	ft_bzero(champ->cor_file, CHAMP_MAX_SIZE + 1);
	champ->lab = NULL;
	champ->lab_pos = NULL;
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
