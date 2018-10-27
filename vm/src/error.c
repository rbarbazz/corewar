/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:01:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/27 13:36:02 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_usage(void)
{
	t_global	*info;

	info = get_global();
	ft_dprintf(STDERR_FILENO, "Usage: %s [-dump nbr_cycles] ", info->prog_name);
	ft_dprintf(STDERR_FILENO, "[[-n number] <champion.cor>] [-v]");
	ft_dprintf(STDERR_FILENO, " [--debug]\n\n");
	ft_dprintf(STDERR_FILENO, "-dump nbr_cycles	: ");
	ft_dprintf(STDERR_FILENO, "Dumps memory after nbr_cycles cycles ");
	ft_dprintf(STDERR_FILENO, "then exits\n-n number		: ");
	ft_dprintf(STDERR_FILENO, "Sets the following <champion.cor>");
	ft_dprintf(STDERR_FILENO, " to the number provided\n");
	ft_dprintf(STDERR_FILENO, "-v			: Visualizer enabled\n");
	ft_dprintf(STDERR_FILENO, "--debug			: Verbose mode\n");
}

static void	error_wrong_pnumber(int error_code)
{
	ft_dprintf(STDERR_FILENO, "[ERROR] %d : Player number", error_code);
	ft_dprintf(STDERR_FILENO, " has to be available");
	ft_dprintf(STDERR_FILENO, ", not 0, between MEM_SIZE and -MEM_SIZE\n");
}

/*
** *****************************************************************************
** prints an error message, frees the memory and exits with the correct err_code
** *****************************************************************************
*/

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
		ft_dprintf(STDERR_FILENO, "[ERROR] %d : Too many champions\n",\
			error_code);
	else if (error_code == NO_CHAMP)
		display_usage();
	else if (error_code == FILE_EMPTY)
		ft_dprintf(STDERR_FILENO, "[ERROR] %d : Champion can't be empty\n",\
			error_code);
	else if (error_code == MALLOC_ERROR)
		ft_dprintf(STDERR_FILENO, "[ERROR] %d : Malloc error\n", error_code);
	else if (error_code == INVALID_MAGIC)
		ft_dprintf(STDERR_FILENO, "[ERROR] %d : Invalid COREWAR_EXEC_MAGIC\n",\
			error_code);
	else if (error_code == WRONG_COMMAND_LENGTH)
		ft_dprintf(STDERR_FILENO, "[ERROR] %d : Champion is too long\n",\
			error_code);
	else if (error_code == WRONG_PNUMBER)
		error_wrong_pnumber(error_code);
	else if (error_code == USAGE_ERROR)
		display_usage();
	free_all();
	exit(error_code);
}
