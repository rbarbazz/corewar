/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:52:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/10 19:49:13 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_name(t_asm *champ)
{
	char	**split;
	int		len;

	if (!(split = strsplit_whitespace(champ->sfile->line)))
		exit_fail();
	if (split[0] && split[1] && !split[2] && \
	(len = ft_strlen(split[1])) <= PROG_NAME_LENGTH)
	{
		if (ft_strequ(split[0], NAME_CMD_STRING) && split[1][0] == '\"'\
		&& split[1][len - 1] == '\"')
		{
			ft_strncpy(champ->header->prog_name, split[1] + 1, len - 2);
			strstr_free(split);
			return (0);
		}
	}
	strstr_free(split);
	ft_printf("Parsing error near line 1 : %s\n", champ->sfile->line);
	return (1);
}

int	parser(t_asm *champ)
{
	if (get_name(champ))
		return (1);
	return (0);
}