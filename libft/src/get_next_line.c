/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:02:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/27 12:03:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(int *last, char **save, char **line)
{
	char	*tmp;

	if (save && *save && ft_strchr(*save, '\n'))
	{
		tmp = *save;
		if (!(*line = dup_to_char(*save, '\n')))
			return (-1);
		if (!(*save = dup_from_char(tmp, '\n')))
			return (-1);
		ft_strdel(&tmp);
		if (*save && !*save[0])
			*last = 1;
		return (1);
	}
	if (!(*line = ft_strdup(*save)))
		return (-1);
	*last = 1;
	return (1);
}

static char	*read_buffer(int *err, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;
	char	*res;

	res = NULL;
	if (!(tmp = ft_strnew(1)))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(res = ft_strjoin(tmp, buf)))
			return (NULL);
		ft_strdel(&tmp);
		tmp = res;
	}
	if (tmp && !tmp[0])
		ft_strdel(&tmp);
	if (ret < 0)
		*err = -1;
	return (res);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	static int	last = 0;
	int			err;

	err = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (last == 1)
	{
		last = 0;
		if (save)
			ft_strdel(&save);
		return (0);
	}
	if (!save)
		if (!(save = read_buffer(&err, fd)))
			return (-1);
	if (err < 0)
		return (err);
	return (check_line(&last, &save, line));
}
