/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:51:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:22:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(const char *format, t_arg *arg, int *i)
{
	if (format && format[*i] && format[*i] == '#')
		arg->flag_sharp = '#';
	else if (format && format[*i] && format[*i] == '-')
		arg->flag = '-';
	else if (format && format[*i] && format[*i] == '+')
		arg->flag_two = '+';
	else if (format && format[*i] && format[*i] == ' ' && arg->flag_two != '+')
		arg->flag_two = ' ';
	else if (format && format[*i] && format[*i] == '0' && arg->flag != '-')
		arg->flag = '0';
	else if (format && format[*i] && format[*i] == ' ' && arg->flag_two == '+')
		arg->flag_two = '+';
	else
		return (1);
	(*i)++;
	return (0);
}

int		check_width(const char *format, t_arg *arg, int *i, va_list ap)
{
	char	*tmp;
	int		itmp;

	itmp = 0;
	if (format && format[*i] && format[*i] == '*')
	{
		arg->width = va_arg(ap, int);
		(*i)++;
		return (0);
	}
	if (!(tmp = ft_strnew(ft_strlen(format))))
		exit(EXIT_FAILURE);
	while (format && format[*i] && ft_isdigit(format[*i]))
		tmp[itmp++] = format[(*i)++];
	if (!tmp[0])
	{
		ft_strdel(&tmp);
		return (1);
	}
	arg->width = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (0);
}

int		check_precision(const char *format, t_arg *arg, int *i, va_list ap)
{
	char	*tmp;
	int		itmp;

	itmp = 0;
	if (format && format[*i] && format[*i] == '.')
	{
		if (format && format[*i + 1] && format[++(*i)] == '*')
		{
			arg->prec = va_arg(ap, int);
			(*i)++;
			return (0);
		}
		if (!(tmp = ft_strnew(ft_strlen(format))))
			exit(EXIT_FAILURE);
		while (format && format[*i] && ft_isdigit(format[*i]))
			tmp[itmp++] = format[(*i)++];
		if (!tmp[0])
			arg->prec = 0;
		arg->prec = ft_atoi(tmp);
		ft_strdel(&tmp);
		return (0);
	}
	return (1);
}

int		check_length(const char *format, t_arg *arg, int *i)
{
	if (format && format[*i] && format[*i] == 'h' && format[*i + 1] == 'h')
	{
		arg->length = "hh\0";
		(*i) = (*i) + 2;
	}
	else if (format && format[*i] && format[*i] == 'l' && format[*i + 1] == 'l')
	{
		arg->length = "ll\0";
		(*i) = (*i) + 2;
	}
	else if (format && format[*i] && format[(*i)] == 'h')
		arg->length = "h\0";
	else if (format && format[*i] && format[(*i)] == 'l')
		arg->length = "l\0";
	else if (format && format[*i] && format[(*i)] == 'j')
		arg->length = "j\0";
	else if (format && format[*i] && format[(*i)] == 'z')
		arg->length = "z\0";
	else
		return (1);
	if (ft_strlen(arg->length) == 1)
		(*i)++;
	return (0);
}

int		check_specifier(const char *format, t_arg *arg, int *i)
{
	if (format && format[*i] && (format[*i] == 's' || format[*i] == 'S'\
		|| format[*i] == 'p' || format[*i] == 'd' || format[*i] == 'D'\
		|| format[*i] == 'i' || format[*i] == 'o' || format[*i] == 'O'\
		|| format[*i] == 'u' || format[*i] == 'U' || format[*i] == 'x'\
		|| format[*i] == 'X' || format[*i] == 'c' || format[*i] == 'C'\
		|| format[*i] == '%'))
		arg->specifier = format[*i];
	else
		return (1);
	return (0);
}
