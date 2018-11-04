/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:27:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:24:49 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_length(t_arg *arg)
{
	int	tmp;
	int len;

	len = 0;
	tmp = arg->ui;
	if (tmp < 0)
	{
		arg->error = 1;
		return (-1);
	}
	while (tmp)
	{
		tmp >>= 1;
		len++;
	}
	return (len);
}

int		wchar2(t_arg *arg)
{
	unsigned int	mask;
	unsigned int	c;

	c = arg->ui;
	if (!arg->ws)
	{
		arg->width -= 2;
		if (arg->flag != '-')
			apply_width(arg);
	}
	if (arg->ws && (arg->savepr >= 0 && ((arg->prec -= 2) < 0)))
		return (0);
	mask = 49280;
	arg->ui = (c << 26) >> 26;
	mask |= arg->ui;
	arg->ui = (((c << 21) >> 27) << 8);
	mask |= arg->ui;
	arg->uc = ((mask << 16) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 24) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	return (0);
}

int		wchar3(t_arg *arg)
{
	unsigned int	mask;
	unsigned int	c;

	c = arg->ui;
	if (!arg->ws)
	{
		arg->width -= 3;
		if (arg->flag != '-')
			apply_width(arg);
	}
	if (arg->ws && (arg->savepr >= 0 && ((arg->prec -= 3) < 0)))
		return (0);
	mask = 14712960;
	arg->ui = (c << 26) >> 26;
	mask |= arg->ui;
	arg->ui = (((c << 20) >> 26) << 8);
	mask |= arg->ui;
	arg->ui = ((c >> 12) << 16);
	mask |= arg->ui;
	add_wchar3(arg, mask);
	return (0);
}

int		wchar4(t_arg *arg)
{
	unsigned long long	mask;
	unsigned long long	c;

	c = arg->ui;
	if (!arg->ws)
	{
		arg->width -= 4;
		if (arg->flag != '-')
			apply_width(arg);
	}
	if (arg->ws && (arg->savepr >= 0 && ((arg->prec -= 4) < 0)))
		return (0);
	mask = 4034953344;
	arg->ui = (c << 58) >> 58;
	mask |= arg->ui;
	arg->ui = (((c << 52) >> 58) << 8);
	mask |= arg->ui;
	arg->ui = (((c << 46) >> 58) << 16);
	mask |= arg->ui;
	arg->ui = (((c << 43) >> 58) << 21);
	mask |= arg->ui;
	add_wchar4(arg, mask);
	return (0);
}

int		convert_wchar(t_arg *arg)
{
	int	len;

	if (arg->ui == 0)
		c_nul(arg);
	len = calc_length(arg);
	if (arg->error == 1)
		return (1);
	if ((MB_CUR_MAX == 1 && len >= 8 && arg->ui > 255) || (arg->ui <= 57343\
		&& arg->ui >= 55296) || arg->ui > 1114111)
	{
		arg->error = 1;
		return (1);
	}
	call_wchar(arg, len);
	if (!arg->ws)
		apply_width(arg);
	arg->retc = ft_strlen(arg->buffer);
	return (0);
}
