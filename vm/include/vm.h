/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamak <msamak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:22:30 by msamak            #+#    #+#             */
/*   Updated: 2018/09/26 16:54:40 by msamak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../libft/include/libft.h"
# include "op.h"

typedef struct			s_process
{
	char				reg[REG_NUMBER][REG_SIZE];
	short				pc;
	int					carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_player
{
	char				*name;
	char				*comment;
}						t_player;

typedef struct			s_global
{
	char				map[MEM_SIZE];
	t_process			*process;
	t_player			player_tab[MAX_PLAYERS];
}						t_global;

/*
** Get the Glabal Structure
*/

t_global				*get_global(void);

#endif
