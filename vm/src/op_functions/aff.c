/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:39:18 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 18:20:17 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		aff(t_global *info, t_process *process)
{
	unsigned int	param0;

	param0 = 0;
	if (get_param_value(info, process, 0, &param0))
		return ;
	if (!param0)
		process->carry = 1;
	else
		process->carry = 0;
	if (!info->visual)
		ft_printf("un process dit : %c\n", param0 % 256);
	ft_printf("un process dit : %d\n", param0 % 256);
}
