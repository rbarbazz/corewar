/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:09:57 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 18:14:13 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_to_ocp(t_asm *champ, int code, int curr_param)
{
	if (!champ->op->has_ocp)
		return ;
	if (curr_param == 0)
		code = code << 2;
	if (curr_param == 1)
		code = code << 4;
	if (curr_param == 2)
		code = code << 6;
	champ->cor_file[champ->curr_ocp] = champ->cor_file[champ->curr_ocp] | code;
}

/*
** check if the param type passed as param matches with the expected type
*/

void		check_param_type(t_arg_type type, t_op *op, int curr_param)
{
	int	i;

	i = 0;
	while (i < 17 && !ft_strequ(g_op_tab[i].name, op->name))
	 	i++;
	if (g_op_tab[i].param[curr_param] == (g_op_tab[i].param[curr_param] | type))
		return ;
	else
		error_parse();
}

/*
** check if the params found match with how many and which are expected
** adds the params to the cor_file buffer and makes the opcode
*/

void	check_op_param(t_asm *champ, t_op *op)
{
	int	curr_param;

	curr_param = 0;
	if (op->has_ocp)
		champ->curr_ocp = champ->header->prog_size++;
	while (curr_param < op->nb_param)
	{
		skip_space();
		if (check_reg(champ, champ->op, curr_param))
			add_to_ocp(champ, REG_CODE, curr_param);
		/*else if //check direct(champ->sfile && champ->sfile[champ->i] == DIRECT_CHAR)
		{}
		else if //check indirect
		{}
		else
		{} //error_parse
		if (curr_param + 1 < op->nb_param)
		{} // check SEPARATOR_CHAR*/
		curr_param++;
	}
}
