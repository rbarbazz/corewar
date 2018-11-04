/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:51:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/31 08:24:35 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wstrlenprec(t_arg *arg, int len)
{
	int	lenchar;
	int	i;

	i = 0;
	while (arg->ws && arg->ws[i])
	{
		arg->ui = arg->ws[i++];
		lenchar = calc_length(arg);
		if (lenchar <= 7 || (arg->ui <= 255 && arg->ui >= 127\
			&& MB_CUR_MAX == 1))
		{
			len++;
			arg->prec--;
		}
		else if (lenchar >= 8 && lenchar <= 11 && (arg->savepr >= 0\
			&& ((arg->prec -= 2) > 0)))
			len += 2;
		else if (lenchar >= 12 && lenchar <= 16 && (arg->savepr >= 0\
			&& ((arg->prec -= 3) > 0)))
			len += 3;
		else if (lenchar >= 17 && lenchar <= 21 && (arg->savepr >= 0\
			&& ((arg->prec -= 4) > 0)))
			len += 4;
	}
	return (len);
}

static int		ft_wstrlen(t_arg *arg, int len)
{
	int	lenchar;
	int	i;

	i = 0;
	while (arg->ws[i])
	{
		arg->ui = arg->ws[i++];
		lenchar = calc_length(arg);
		if (lenchar <= 7 || (arg->ui <= 255 && arg->ui >= 127\
			&& MB_CUR_MAX == 1))
			len++;
		else if (lenchar >= 8 && lenchar <= 11)
			len += 2;
		else if (lenchar >= 12 && lenchar <= 16)
			len += 3;
		else if (lenchar >= 17 && lenchar <= 21)
			len += 4;
	}
	return (len);
}

static int		add_ws(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg->ws && arg->ws[i] && arg->prec)
	{
		arg->ui = arg->ws[i++];
		convert_wchar(arg);
	}
	return (0);
}

int				convert_ws(t_arg *arg)
{
	int		len;

	len = 0;
	arg->savepr = arg->prec;
	if (!arg->ws)
	{
		convert_s(arg);
		return (0);
	}
	if (arg->prec >= 0)
		len = ft_wstrlenprec(arg, len);
	else
		len = ft_wstrlen(arg, len);
	arg->prec = arg->savepr;
	if (arg->prec < 0 || arg->prec > arg->width || arg->prec > len)
		arg->width -= len;
	else if (len > 0)
		arg->width -= arg->prec;
	if (arg->flag != '-')
		apply_width(arg);
	add_ws(arg);
	apply_width(arg);
	return (0);
}

int				convert_s(t_arg *arg)
{
	char	*nul;
	int		len;
	int		i;

	nul = "(null)";
	i = 0;
	if (!arg->s)
		arg->s = nul;
	len = (int)ft_strlen(arg->s);
	if (arg->prec < 0 || arg->prec > arg->width || arg->prec > len)
		arg->width -= len;
	else if (len > 0)
		arg->width -= arg->prec;
	if (arg->flag != '-')
		apply_width(arg);
	while (arg->s && arg->s[i] && arg->prec--)
		arg->buffer = strcatchar(arg->buffer, arg->s[i++]);
	apply_width(arg);
	return (0);
}
