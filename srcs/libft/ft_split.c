/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:41:49 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:41:51 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_count_word(char const *s, char ch)
{
	int	size;
	int	flag;

	size = 0;
	flag = 1;
	while (*s)
	{
		if (*s != ch && flag)
		{
			size++;
			flag = 0;
		}
		else if (*s == ch)
			flag = 1;
		s++;
	}
	return (size);
}

static	void	ft_all_clear(char **new, int count_word)
{
	int	i;

	i = 0;
	while (i < count_word)
		free(*(new + i++));
	free(new);
}

static	void	ft_edit(char **new, char const *s, char ch, int count_word)
{
	unsigned	k;
	size_t		size;

	k = 0;
	while (count_word--)
	{
		size = 0;
		while (*(s + k) == ch)
			k++;
		while (*(s + k + size) != ch && *(s + k + size))
			size++;
		if (size != 0)
			*new = ft_substr(s, k, size);
		if (!(*new))
		{
			ft_all_clear(new, count_word);
			return ;
		}
		k = k + size;
		new++;
	}
}

char			**ft_split(char const *s, char ch)
{
	int		count_word;
	char	**new;

	if (!s)
		return (NULL);
	count_word = ft_get_count_word(s, ch);
	new = (char**)malloc(sizeof(char*) * (count_word + 1));
	if (!new)
		return (NULL);
	*(new + count_word) = 0;
	ft_edit(new, s, ch, count_word);
	return (new);
}
