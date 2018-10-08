/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:01:35 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 15:05:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** prints an error message, frees the memory and exits with the correct err_code
** *****************************************************************************
*/

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
		ft_printf("[ERROR] %d : Too many champions\n", error_code);
	if (error_code == NO_CHAMP)
		ft_printf("[ERROR] %d : No champion provided\n", error_code);
	if (error_code == FILE_EMPTY)
		ft_printf("[ERROR] %d : Champion can't be empty\n", error_code);
	if (error_code == READ_FILE_ERROR)
		exit(READ_FILE_ERROR);
	if (error_code == INVALID_CLOSE_FD)
		exit(INVALID_CLOSE_FD);
	if (error_code == MALLOC_ERROR)
		ft_printf("[ERROR] %d : Malloc : Error - [Protected]\n", error_code);
	if (error_code == INVALID_MAGIC)
		ft_printf("[ERROR] %d : Invalid COREWAR_EXEC_MAGIC\n", error_code);
	if (error_code == WRONG_COMMAND_LENGTH)
		ft_printf("[ERROR] %d : champion is too long\n", error_code);
	free_all();
	exit(error_code);
}
