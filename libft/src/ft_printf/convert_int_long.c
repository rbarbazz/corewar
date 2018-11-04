/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:19:32 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:23:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_precision(t_arg *arg)
{
	while (arg->prec-- > 0)
		arg->buffer = strcatchar(arg->buffer, '0');
	return (0);
}

static int	apply_flags(t_arg *arg)
{
	if (arg->flag_sharp && arg->itoaed[0] != '0' && (arg->specifier == 'o'\
		|| arg->specifier == 'O'))
		arg->buffer = strcatchar(arg->buffer, '0');
	else if (arg->flag_sharp && arg->itoaed[0] != '0' && (arg->specifier == 'x'\
		|| arg->specifier == 'X'))
	{
		if (arg->specifier == 'x')
		{
			arg->buffer = strcatchar(arg->buffer, '0');
			arg->buffer = strcatchar(arg->buffer, 'x');
		}
		if (arg->specifier == 'X')
		{
			arg->buffer = strcatchar(arg->buffer, '0');
			arg->buffer = strcatchar(arg->buffer, 'X');
		}
	}
	if (arg->flag_two == '+' && !ft_strchr("uUoOxX", arg->specifier))
		arg->buffer = strcatchar(arg->buffer, '+');
	else if (arg->flag_two == ' ' && arg->specifier != 'u')
		arg->buffer = strcatchar(arg->buffer, ' ');
	return (0);
}

static int	calc_width_and_precision(t_arg *arg)
{
	arg->width -= ft_strlen(arg->itoaed);
	if (arg->itoaed[0] == '0' && arg->prec == 0)
		arg->width += ft_strlen(arg->itoaed);
	if ((arg->flag_sharp && arg->itoaed[0] != '0' && (arg->specifier == 'o'\
		|| arg->specifier == 'O' || arg->specifier == 'x' || arg->specifier\
		== 'X')) || (arg->flag_two && arg->itoaed[0] != '-'))
	{
		if (arg->specifier == 'x' || arg->specifier == 'X')
			arg->width--;
		arg->width--;
		if ((arg->specifier == 'o' || arg->specifier == 'O') && arg->flag_sharp\
			&& arg->prec)
			arg->prec--;
	}
	if (arg->prec >= 0)
		arg->prec -= ft_strlen(arg->itoaed);
	if (arg->itoaed[0] == '-')
	{
		arg->flag_two = '\0';
		arg->prec++;
	}
	if (arg->prec >= 0)
		arg->width -= arg->prec;
	return (0);
}

static void	apply_modifiers(t_arg *arg)
{
	apply_flags(arg);
	apply_precision(arg);
}

int			convert_int_long(t_arg *arg)
{
	int		save;
	int		i;

	i = 0;
	save = arg->prec;
	calc_width_and_precision(arg);
	if (!arg->flag)
		apply_width(arg);
	if (arg->itoaed[0] == '-')
	{
		arg->buffer = strcatchar(arg->buffer, '-');
		ft_memmove(arg->itoaed, arg->itoaed + 1, ft_strlen(arg->itoaed + 1)\
			+ 1);
	}
	apply_modifiers(arg);
	if (arg->width > 0 && arg->flag != '-')
		apply_width(arg);
	if ((arg->itoaed[0] == '0' && !save && !arg->flag_sharp) || (arg->itoaed[0]\
		== '0' && !save && (arg->specifier == 'x' || arg->specifier == 'X')\
		&& arg->flag_sharp))
		return (0);
	while (arg->itoaed && arg->itoaed[i])
		arg->buffer = strcatchar(arg->buffer, arg->itoaed[i++]);
	apply_width(arg);
	return (0);
}
