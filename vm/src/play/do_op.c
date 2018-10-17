/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:09:15 by msamak            #+#    #+#             */
/*   Updated: 2018/10/17 16:22:16 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_op(t_global *info, t_process *process)
{
	void (*op_ft[16])(t_global*, t_process*);

	op_ft[0] = live;
	op_ft[1] = ld;
	op_ft[2] = st;
	op_ft[3] = add;
	op_ft[4] = sub;
	op_ft[5] = and_vm;
	op_ft[6] = or_vm;
	op_ft[7] = xor_vm;
	op_ft[8] = zjmp;
	op_ft[9] = ldi;
	op_ft[10] = sti;
	op_ft[11] = fork_vm;
	op_ft[12] = lld;
	op_ft[13] = lldi;
	op_ft[14] = lfork;
	op_ft[15] = aff;
	op_ft[process->curr_op.opcode - 1](info, process);
}
