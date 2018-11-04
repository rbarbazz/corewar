/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:53:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:25:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_conversion_by_type(va_list ap, t_arg *arg)
{
	if (check_type_char(ap, arg) == 1)
	{
		if (check_type_array(ap, arg) == 1)
		{
			if (check_type_long(ap, arg) == 1)
			{
				if (check_type_long2(ap, arg) == 1)
				{
					if (check_type_int(ap, arg) == 1)
					{
						if (check_type_short(ap, arg) == 1)
						{
							arg->p = va_arg(ap, void*);
							convert_p(arg);
						}
					}
				}
			}
		}
	}
	else
		return (1);
	return (0);
}

static int		check_format(const char *format, t_arg *arg, int i, va_list ap)
{
	while (format && format[i] && check_specifier(format, arg, &i) == 1)
	{
		if (check_flags(format, arg, &i) == 1\
			&& check_width(format, arg, &i, ap) == 1\
			&& check_precision(format, arg, &i, ap) == 1\
			&& check_length(format, arg, &i) == 1)
		{
			check_specifier(format, arg, &i);
			break ;
		}
		while (format && format[i] && !ft_isprint(format[i]))
			i++;
	}
	if (arg->prec >= 0 && arg->flag == '0' && arg->specifier != '%')
		arg->flag = '\0';
	return (i);
}

static int		init_struct(t_arg *arg, int *i)
{
	arg->flag = '\0';
	arg->flag_two = '\0';
	arg->flag_sharp = '\0';
	arg->width = 0;
	arg->prec = -1;
	arg->length = "";
	arg->specifier = '\0';
	arg->s = NULL;
	arg->p = NULL;
	arg->ui = 0;
	arg->uc = '\0';
	arg->ws = NULL;
	(*i)++;
	return (0);
}

static int		check_and_convert(const char *format, t_arg *arg, va_list ap)
{
	int	i;

	i = 0;
	arg->ret = 0;
	while (format && format[i] && arg->error == 0)
	{
		if (format[i] == '%')
		{
			init_struct(arg, &i);
			i = check_format(format, arg, i, ap);
			if (arg->specifier)
			{
				handle_conversion_by_type(ap, arg);
				i++;
			}
			else
				return (1);
		}
		else
		{
			arg->buffer = strcatchar(arg->buffer, format[i]);
			i++;
		}
	}
	return (0);
}

int				ft_dprintf(int fd, char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	if (!format || !(arg.buffer = ft_strnew(1)))
		exit(EXIT_FAILURE);
	arg.error = 0;
	arg.errorno = 0;
	arg.retc = 0;
	arg.fd = fd;
	va_start(ap, format);
	arg.errorno = check_and_convert(format, &arg, ap);
	va_end(ap);
	if (arg.error == 0)
		arg.ret += write(arg.fd, arg.buffer, ft_strlen(arg.buffer));
	else
	{
		arg.ret = -1;
		if (!ft_strchr("sS", arg.specifier))
			write(arg.fd, arg.buffer, arg.retc);
	}
	if (arg.errorno == 1)
		arg.ret = 0;
	ft_strdel(&arg.buffer);
	return (arg.ret);
}
