/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:24:26 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/10 17:24:32 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** *****************************************************************************
** 1 - check the arguments and the inputs from the user
** 2 - create the main structure containing players, process and map
** 3 - start the main loop with play()
** 4 - free memory and exit
** *****************************************************************************
*/

int			main(int argc, char **argv)
{
	t_global	*info;

	info = get_global();
	init_global(info, argv[0]);
	check_args(info, argc, argv);
	create_map(info);
	write_player_in_map(info);
	play(info);
	exit_corewar(SUCCESS);
	return (SUCCESS);
}
