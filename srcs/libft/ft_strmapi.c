/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:12 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:14 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s == NULL || f == NULL)
		return (NULL);
	i = -1;
	new = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (!new)
		return (NULL);
	while (*(s + ++i))
		*(new + i) = f(i, *(s + i));
	*(new + i) = '\0';
	return (new);
}
