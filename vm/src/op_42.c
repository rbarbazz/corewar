/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:29:13 by msamak            #+#    #+#             */
/*   Updated: 2018/10/11 16:29:33 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op	g_op_tab[16] =
{
	{"live", 1, {T_DIR}, 1, 10, 0, 0},
	{"ld", 2, {T_REG | T_DIR | T_IND, T_REG}, 2, 5, 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 0},
	{"zjmp", 1, {T_IND}, 9, 20, 0, 1},
	{"ldi", 3, {T_IND, T_IND, T_REG}, 10, 25, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_IND, T_IND | T_REG}, 11, 25, 1, 1},
	{"fork", 1, {T_IND}, 12, 800, 0, 1},
	{"lld", 2, {T_DIR | T_IND | T_REG, T_REG}, 13, 10, 1, 0},
	{"lldi", 3, {T_IND, T_IND, T_REG}, 14, 50, 1, 1},
	{"lfork", 1, {T_IND}, 15, 1000, 0, 1},
	{"aff", 1, {T_REG}, 16, 2, 1, 0},
};