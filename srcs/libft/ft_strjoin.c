/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:30 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:32 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if (!(new = (char*)malloc(sizeof(char) *
	(ft_strlen((char*)s1) + ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s1 && *(s1 + i))
	{
		*(new + i) = *(s1 + i);
		i++;
	}
	while (s && *(s + k))
	{
		*(new + i + k) = *(s + k);
		k++;
	}
	*(new + i + k) = '\0';
	if (s1 != NULL)
		free(s1);
	if (s != NULL)
		free(s);
	return (new);
}
