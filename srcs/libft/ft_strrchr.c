/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:00 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:01 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	size;

	size = ft_strlen((char*)str);
	while (size != -1)
	{
		if (*(str + size) == ch)
			return ((char*)(str + size));
		size--;
	}
	return (NULL);
}
