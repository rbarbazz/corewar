/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:01:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 17:13:39 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_usage(void)
{
	t_global	*info;

	info = get_global();
	ft_printf("Usage:	%s", info->prog_name);
	ft_printf(" [-dump nbr_cycles] [[-n number] <champion.cor>] [-v]\n\n");
	ft_printf("-dump nbr_cycles		: ");
	ft_printf("Dumps memory after nbr_cycles cycles then exits\n");
	ft_printf("-n number <champion.cor>	: ");
	ft_printf("Sets <champion.cor> to the number provided\n");
	ft_printf("-v				: Visualizer enabled\n");
}

/*
** *****************************************************************************
** prints an error message, frees the memory and exits with the correct err_code
** *****************************************************************************
*/

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
		ft_printf("[ERROR] %d : Too many champions\n", error_code);
	else if (error_code == NO_CHAMP)
		display_usage();
	else if (error_code == FILE_EMPTY)
		ft_printf("[ERROR] %d : Champion can't be empty\n", error_code);
	else if (error_code == MALLOC_ERROR)
		ft_printf("[ERROR] %d : Malloc : Error - [Protected]\n", error_code);
	else if (error_code == INVALID_MAGIC)
		ft_printf("[ERROR] %d : Invalid COREWAR_EXEC_MAGIC\n", error_code);
	else if (error_code == WRONG_COMMAND_LENGTH)
		ft_printf("[ERROR] %d : champion is too long\n", error_code);
	else if (error_code == USAGE_ERROR)
		display_usage();
	free_all();
	exit(error_code);
}
