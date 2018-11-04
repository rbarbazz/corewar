/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:10:07 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:27:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type_array(va_list ap, t_arg *arg)
{
	if (arg->specifier == 'S' || (arg->specifier == 's'\
		&& !ft_strcmp(arg->length, "l")))
	{
		arg->ws = va_arg(ap, unsigned int*);
		convert_ws(arg);
	}
	else if (arg->specifier == 's')
	{
		arg->s = va_arg(ap, char*);
		convert_s(arg);
	}
	else
		return (1);
	return (0);
}

int	add_wchar3(t_arg *arg, unsigned int mask)
{
	arg->uc = ((mask << 8) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 16) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 24) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	return (0);
}

int	add_wchar4(t_arg *arg, unsigned long long mask)
{
	arg->uc = (mask >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 8) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 16) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	arg->uc = ((mask << 24) >> 24);
	arg->buffer = strcatchar(arg->buffer, arg->uc);
	return (0);
}

int	call_wchar(t_arg *arg, int len)
{
	if (len <= 7 || (arg->ui <= 255 && arg->ui >= 127 && MB_CUR_MAX == 1))
	{
		if (!arg->ws)
		{
			arg->width--;
			if (arg->flag != '-')
				apply_width(arg);
		}
		if (arg->ws && (arg->savepr >= 0 && ((arg->prec--) < 0)))
			return (0);
		arg->buffer = strcatchar(arg->buffer, arg->ui);
	}
	else if (len >= 8 && len <= 11)
		wchar2(arg);
	else if (len >= 12 && len <= 16)
		wchar3(arg);
	else if (len >= 17 && len <= 21)
		wchar4(arg);
	return (0);
}

int	check_type_long2(va_list ap, t_arg *arg)
{
	char *itoa;

	if (arg->specifier == 'O' || (arg->specifier == 'o'\
		&& ft_strcmp(arg->length, "h") && ft_strcmp(arg->length, "")\
		&& ft_strcmp(arg->length, "hh")))
		itoa = ft_itoa_u(va_arg(ap, unsigned long long), 8, 0);
	else if (arg->specifier == 'U' || (arg->specifier == 'u'\
		&& ft_strcmp(arg->length, "h") && ft_strcmp(arg->length, "")\
		&& ft_strcmp(arg->length, "hh")))
		itoa = ft_itoa_u(va_arg(ap, unsigned long long), 10, 0);
	else
		return (1);
	if (!(arg->itoaed = itoa))
		exit(EXIT_FAILURE);
	convert_int_long(arg);
	ft_strdel(&itoa);
	return (0);
}
