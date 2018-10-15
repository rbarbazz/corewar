/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompagn <lcompagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:46:45 by lcompagn          #+#    #+#             */
/*   Updated: 2018/10/15 13:47:18 by lcompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_instructions(void)
{
	attron(A_UNDERLINE);
	mvprintw(INSTRUCTION_LINE, 2, "Usage");
	attroff(A_UNDERLINE);
	mvprintw(INSTRUCTION_LINE + 1, 2, "\t- (Un)pause :\t[Space]");
	mvprintw(INSTRUCTION_LINE + 2, 2, "\t- Next step :\t[%c]", KEY_STEP);
	mvprintw(INSTRUCTION_LINE + 3, 2, "\t- Faster :\t[%c]", KEY_SLEEP_DOWN);
	mvprintw(INSTRUCTION_LINE + 4, 2, "\t- Slower :\t[%c]", KEY_SLEEP_UP);
}
