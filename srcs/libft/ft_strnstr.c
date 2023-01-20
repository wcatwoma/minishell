/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:04 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:06 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	k;

	if (*find == '\0')
		return ((char*)str);
	i = 0;
	while (i < len && *(str + i))
	{
		k = 0;
		while (*(str + i + k) == *(find + k) &&
				(i + k) < len && *(find + k) && *(str + i + k))
			k++;
		if (*(find + k) == '\0')
			return ((char*)str + i);
		i++;
	}
	return (NULL);
}
