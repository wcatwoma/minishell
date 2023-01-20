/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:45:10 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:45:12 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	check_redirect(char *line, char *str)
{
	size_t	i;
	int		quotation;

	i = 0;
	quotation = 0;
	while (line[i])
	{
		if ((ft_issemicolon(line[i]) && !i)
			|| (ft_issemicolon(line[i]) && line[i - 1] != '\\'))
			quotation = !quotation;
		if (!quotation && !ft_strncmp(line + i, str, ft_strlen(str)))
			return (i + 1);
		i++;
	}
	return (0);
}

int	init_check_id(t_token *tokens, char *line)
{
	tokens->one = check_token(line, ';');
	tokens->two = check_redirect(line, ">>>");
	tokens->three = check_redirect(line, "<<");
	tokens->four = check_token(line, '|');
	if (!(tokens->four + tokens->two + tokens->one + tokens->three))
		return (0);
	tokens->one = !tokens->one ? ~0 : tokens->one - 1;
	tokens->two = !tokens->two ? ~0 : tokens->two - 1;
	tokens->three = !tokens->three ? ~0 : tokens->three - 1;
	tokens->four = !tokens->four ? ~0 : tokens->four - 1;
	return (1);
}

char	*get_error_token(t_token *tokens, char *line)
{
	if (tokens->one < tokens->two && tokens->one < tokens->four
		&& tokens->one < tokens->three)
		return (!ft_strncmp(line + tokens->one, ";;", 2) ? ";;" : ";");
	else if (tokens->four < tokens->two && tokens->four < tokens->one
		&& tokens->four < tokens->three)
		return (!ft_strncmp(line + tokens->four, "||", 2) ? "||" : "|");
	else if (tokens->two < tokens->four && tokens->two < tokens->one
		&& tokens->two < tokens->three)
		return (!ft_strncmp(line + tokens->two, ">>>>", 4) ? ">>" : ">");
	else if (!ft_strcmp(line + tokens->three, "<<<<"))
		return ("<");
	else if (!ft_strcmp(line + tokens->three, "<<<<<"))
		return ("<<");
	else if (!ft_strncmp(line + tokens->three, "<<<<<<", 6))
		return ("<<<");
	return (NULL);
}

int		check_back_redirect(char *line)
{
	int		quotation;
	int		i;

	quotation = 0;
	i = 0;
	while (line[i])
	{
		if ((ft_issemicolon(line[i]) && !i) ||
			(ft_issemicolon(line[i]) && line[i - 1] != '\\'))
			quotation = !quotation;
		if (!quotation && line[i] == '<' &&
			!check(line + i + 1, ft_isspace, '\0'))
			return (1);
		if (quotation && line[i] == ';')
			line[i] = CODE_SEMICOLON;
		i++;
	}
	return (0);
}

int		check_line(t_env *env, char *line)
{
	t_token	tokens;
	char	*str;

	replace_semicolon(line);
	if (!init_check_id(&tokens, line))
		return (check_back_redirect(line));
	str = get_error_token(&tokens, line);
	if (str)
		ft_error(str, NULL, ERROR_TOKEN, env->fd_write);
	return (1);
}
