/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_screen_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:50:50 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/11 17:05:03 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_check_screen_size(void)
{
	if (LINES < LINES_LIM || COLS < TOTAL_COLS)
		return (1);
	return (SUCCESS);
}
