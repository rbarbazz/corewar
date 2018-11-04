/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:34:11 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/23 11:49:36 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;
	t_list	*nxt;

	temp = *alst;
	nxt = NULL;
	while (temp)
	{
		nxt = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = nxt;
	}
	*alst = NULL;
}
