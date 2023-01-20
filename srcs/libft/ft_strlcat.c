/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:26 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:28 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_res;

	size_dest = ft_strlen(dest);
	if (size < size_dest)
		return (size + ft_strlen((char*)src));
	size_res = size_dest + ft_strlen((char*)src);
	if (size > 0)
	{
		while (*src && size_dest < size - 1)
			dest[size_dest++] = *src++;
		dest[size_dest] = '\0';
	}
	return (size_res);
}
