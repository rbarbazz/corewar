/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:01:56 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/28 14:01:07 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_arg
{
	int					ret;
	char				*buffer;
	char				flag;
	char				flag_two;
	char				flag_sharp;
	int					width;
	int					prec;
	char				*length;
	char				specifier;
	int					error;
	int					errorno;
	int					retc;
	int					savepr;
	int					fd;
	char				*s;
	unsigned int		*ws;
	void				*p;
	unsigned int		ui;
	unsigned char		uc;
	char				*itoaed;
}					t_arg;

int					ft_printf(char const *format, ...);
int					ft_dprintf(int fd, char const *format, ...);

int					check_flags(const char *format, t_arg *arg, int *i);
int					check_width(const char *format, t_arg *arg, int *i,\
	va_list ap);
int					check_precision(const char *format, t_arg *arg, int *i,\
	va_list ap);
int					check_length(const char *format, t_arg *arg, int *i);
int					check_specifier(const char *format, t_arg *arg, int *i);

int					check_type_char(va_list ap, t_arg *arg);
int					check_type_array(va_list ap, t_arg *arg);
int					check_type_short(va_list ap, t_arg *arg);
int					check_type_int(va_list ap, t_arg *arg);
int					check_type_long(va_list ap, t_arg *arg);
int					check_type_long2(va_list ap, t_arg *arg);

int					convert_c(t_arg *arg);
int					convert_s(t_arg *arg);
int					convert_p(t_arg *arg);
int					convert_int_long(t_arg *arg);
int					convert_wchar(t_arg *arg);
int					convert_ws(t_arg *arg);
int					apply_width(t_arg *arg);
int					calc_length(t_arg *arg);
int					c_nul(t_arg *arg);
int					add_wchar3(t_arg *arg, unsigned int mask);
int					add_wchar4(t_arg *arg, unsigned long long mask);
int					call_wchar(t_arg *arg, int len);
int					wchar2(t_arg *arg);
int					wchar3(t_arg *arg);
int					wchar4(t_arg *arg);

#endif
