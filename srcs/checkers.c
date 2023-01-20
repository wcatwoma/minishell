/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:45:19 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 22:39:21 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_issemicolon(int ch)
{
	if (ch == '\"' || ch == '\'')
		return (1);
	return (0);
}

int		check(char *str, int (*func)(int), char ch)
{
	int		i;

	i = -1;
	while (str[++i] != ch && str[i])
		if (!func(str[i]))
			return (1);
	return (0);
}

int		check_value_env(char *str)
{
	if (ft_isalpha(*str) || *str == '_')
		str++;
	else
		return (1);
	while (ft_isalnum(*str) || *str == '_')
		str++;
	if (*str == '=' || !*str)
		return (0);
	return (1);
}

int		check_env(t_env *env, char *str)
{
	int		i;
	int		size_key;

	if (check_value_env(str) || str[0] == '=')
		return (-1);
	i = presence_env(env, str);
	return (i == -1 ? -2 : i);
}

size_t	check_token(char *line, char ch)
{
	size_t	i;
	int		flag;
	int		quotation;

	i = 0;
	flag = 0;
	quotation = 0;
	while (line[i])
	{
		if (!quotation && ((!flag && line[i] == ch) ||
			(line[i] == ch && line[i + 1] == ch)))
			return (i + 1);
		if (line[i] == '|' || line[i] == ';' ||
			line[i] == '<' || line[i] == '>')
			flag = 0;
		else if (line[i] != ' ' && line[i] != ch)
			flag = 1;
		if ((ft_issemicolon(line[i]) && !i)
			|| (ft_issemicolon(line[i]) && line[i - 1] != '\\'))
			quotation = !quotation;
		i++;
	}
	return (0);
}
