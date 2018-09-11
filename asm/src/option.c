/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:26:47 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/11 18:33:49 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 2] == '.' && filename[len - 1] == 's')
		return (0);
	return (1);
}

char	*check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (NULL);
	if (argc == 3 && ft_strcmp(argv[1], "-a") != 0)
		return (NULL);
	if (check_file_extension(argv[argc - 1]))
		return (NULL);
	return (argv[argc - 1]);
}
