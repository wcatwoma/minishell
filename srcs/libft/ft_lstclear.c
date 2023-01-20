/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:43:52 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:43:54 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void*))
{
	t_list	*t;

	if (!list || !del)
		return ;
	while (*list)
	{
		t = (*list)->next;
		del((*list)->content);
		free(*list);
		*list = t;
	}
}
