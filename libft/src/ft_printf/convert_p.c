/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 09:47:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/30 16:24:07 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_width(t_arg *arg)
{
	while (arg->width-- > 0)
	{
		if (arg->flag == '0')
			arg->buffer = strcatchar(arg->buffer, '0');
		else
			arg->buffer = strcatchar(arg->buffer, ' ');
	}
	return (0);
}

int		convert_p(t_arg *arg)
{
	char	*itoa;
	char	*ptr;
	char	*nul;
	int		i;

	nul = "0x";
	i = 0;
	if (!(itoa = ft_itoa((unsigned long)arg->p, 16, 0)))
		exit(EXIT_FAILURE);
	ptr = itoa;
	if (arg->p)
		arg->width = arg->width - ft_strlen(ptr) - 2;
	else
		arg->width -= 3;
	if (!arg->flag)
		apply_width(arg);
	while (nul[i])
		arg->buffer = strcatchar(arg->buffer, nul[i++]);
	if (!arg->p)
		arg->buffer = strcatchar(arg->buffer, '0');
	while (arg->p && *ptr)
		arg->buffer = strcatchar(arg->buffer, *ptr++);
	apply_width(arg);
	ft_strdel(&itoa);
	return (0);
}
