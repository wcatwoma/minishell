/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:40:55 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:40:57 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isletter(char letter, char *str)
{
	while (*str)
		if (*str++ == letter)
			return (1);
	return (0);
}

static int		ft_get_end(char *s1, char *set, int size)
{
	while (ft_isletter(*(s1 + size), set))
		size--;
	return (size + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_isletter(*((char*)s1 + start), (char*)set))
		start++;
	end = ft_get_end((char*)s1, (char*)set, ft_strlen((char*)s1) - 1);
	if (end - start < 1)
		new = ft_substr("", 0, 0);
	else
		new = ft_substr(s1, (unsigned int)start, (size_t)(end - start));
	return (new);
}
