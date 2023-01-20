/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:43 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:45 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (*(s + ++i))
		if (*(s + i) == c)
			return ((char*)s + i);
	if (*(s + i) == c)
		return ((char*)s + i);
	return (NULL);
}
