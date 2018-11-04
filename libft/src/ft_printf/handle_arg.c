/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:39:08 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:26:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type_int(va_list ap, t_arg *arg)
{
	char *itoa;

	itoa = NULL;
	if (ft_strchr("id", arg->specifier) && !ft_strcmp("", arg->length))
		itoa = ft_itoa(va_arg(ap, int), 10, 0);
	else if (ft_strchr("id", arg->specifier) && !ft_strcmp("h", arg->length))
		itoa = ft_itoa((short)va_arg(ap, int), 10, 0);
	else if (arg->specifier == 'x' && (!ft_strcmp("", arg->length)\
		|| !ft_strcmp("h", arg->length)))
		itoa = ft_itoa_u(va_arg(ap, unsigned int), 16, 0);
	else if (arg->specifier == 'X' && (!ft_strcmp("", arg->length)\
		|| !ft_strcmp("h", arg->length)))
		itoa = ft_itoa_u(va_arg(ap, unsigned int), 16, 1);
	else if (arg->specifier == 'u' && (!ft_strcmp("", arg->length)\
		|| !ft_strcmp("h", arg->length)))
		itoa = ft_itoa_u(va_arg(ap, unsigned int), 10, 0);
	else if (arg->specifier == 'o' && (!ft_strcmp("", arg->length)))
		itoa = ft_itoa_u(va_arg(ap, unsigned int), 8, 0);
	else
		return (1);
	if (!(arg->itoaed = itoa))
		exit(EXIT_FAILURE);
	convert_int_long(arg);
	ft_strdel(&itoa);
	return (0);
}

int	check_type_long(va_list ap, t_arg *arg)
{
	char *itoa;

	itoa = NULL;
	if ((ft_strchr("di", arg->specifier) && (!ft_strcmp(arg->length, "j")\
		|| !ft_strcmp(arg->length, "ll") || !ft_strcmp(arg->length, "l")))\
		|| ft_strchr("D", arg->specifier))
		itoa = ft_itoa(va_arg(ap, long long), 10, 0);
	else if (ft_strchr("di", arg->specifier) && !ft_strcmp(arg->length, "z"))
		itoa = ft_itoa(va_arg(ap, unsigned long long), 10, 0);
	else if (arg->specifier == 'x' && (ft_strcmp("h", arg->length)\
		&& ft_strcmp("hh", arg->length) && ft_strcmp("", arg->length)))
		itoa = ft_itoa_u(va_arg(ap, unsigned long long), 16, 0);
	else if (arg->specifier == 'X' && (ft_strcmp("h", arg->length)\
		&& ft_strcmp("hh", arg->length)) && ft_strcmp("", arg->length))
		itoa = ft_itoa_u(va_arg(ap, unsigned long long), 16, 1);
	else
		return (1);
	if (!(arg->itoaed = itoa))
		exit(EXIT_FAILURE);
	convert_int_long(arg);
	ft_strdel(&itoa);
	return (0);
}

int	check_type_char(va_list ap, t_arg *arg)
{
	if (arg->specifier == 'C' || (arg->specifier == 'c'\
		&& !ft_strcmp(arg->length, "l")))
	{
		arg->ui = va_arg(ap, unsigned int);
		convert_wchar(arg);
	}
	else if (ft_strchr("c%", arg->specifier))
	{
		if (arg->specifier == 'c')
			arg->uc = va_arg(ap, unsigned int);
		convert_c(arg);
	}
	else
		return (1);
	return (0);
}

int	check_type_short(va_list ap, t_arg *arg)
{
	char *itoa;

	itoa = NULL;
	if (!ft_strcmp(arg->length, "hh"))
	{
		if (ft_strchr("id", arg->specifier))
			itoa = ft_itoa((char)va_arg(ap, int), 10, 0);
		else if (ft_strchr("o", arg->specifier))
			itoa = ft_itoa((unsigned char)va_arg(ap, int), 8, 0);
		else if (ft_strchr("u", arg->specifier))
			itoa = ft_itoa((unsigned char)va_arg(ap, int), 10, 0);
		else if (ft_strchr("x", arg->specifier))
			itoa = ft_itoa((unsigned char)va_arg(ap, int), 16, 0);
		else
			itoa = ft_itoa((unsigned char)va_arg(ap, int), 16, 1);
	}
	else if (arg->specifier == 'o' && !ft_strcmp("h", arg->length))
		itoa = ft_itoa_u((unsigned short)va_arg(ap, unsigned int), 8, 0);
	else
		return (1);
	if (!(arg->itoaed = itoa))
		exit(EXIT_FAILURE);
	convert_int_long(arg);
	ft_strdel(&itoa);
	return (0);
}
