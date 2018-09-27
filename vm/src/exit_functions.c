/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:32:26 by msamak            #+#    #+#             */
/*   Updated: 2018/09/27 18:55:09 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		exit_corewar(int error_code)
{
	if (error_code == TOO_MANY_ARGS)
	{
		ft_printf("Too many champions\n");
		exit(TOO_MANY_ARGS);
	}
	if (error_code == FILE_EMPTY)
	{
		ft_printf("Champion can't be empty\n");
		exit(FILE_EMPTY);
	}
	if (error_code == READ_FILE_ERROR)
		exit(READ_FILE_ERROR);
}
