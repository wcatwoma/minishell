/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:43 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:45 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	shielding_dolar(t_env *env, char **str, int i)
{
	char	*new_str;
	char	*tmp;
	int		start;
	int		end;

	start = i;
	if (ft_isdigit((*str)[i]) || (*str)[i] == '?')
		i++;
	else
		while (ft_isalnum((*str)[i]) || (*str)[i] == '_')
			i++;
	tmp = ft_substr(*str, start, i - start);
	new_str = ft_strjoin(ft_substr(*str, 0, start - 1),
		(*str)[i - 1] == '?' ? ft_itoa(errno) : get_value_env(env, tmp));
	new_str = ft_strjoin(new_str, ft_substr(*str, i, ft_strlen(*str + i)));
	free(tmp);
	free(*str);
	*str = new_str;
}

void	replace_symbols(char **str, int i)
{
	if ((*str)[i] == ' ')
		(*str)[i] = CODE_SPACE;
	else if ((*str)[i] == '>')
		(*str)[i] = CODE_REDIRECT;
	else if ((*str)[i] == '<')
		(*str)[i] = CODE_BACK_REDIRECT;
	else if ((*str)[i] == '|')
		(*str)[i] = CODE_PIPE;
	else if ((*str)[i] == ';')
		(*str)[i] = CODE_SEMICOLON;
}

void	shielding_one(t_data *data, char **str, int *i)
{
	if (!(data->quotation || data->quotation_signle) &&
		(!ft_strncmp((*str) + *i, "\"\" ", 3) ||
		!ft_strncmp((*str) + *i, "\'\' ", 3)))
	{
		(*str)[*i] = CODE_ARGV;
		(*str)[*i + 1] = ' ';
	}
	if (!(data->quotation || data->quotation_signle) &&
		(!ft_strcmp((*str) + *i, "\"\"") ||
		!ft_strcmp((*str) + *i, "\'\'")))
	{
		(*str)[*i] = CODE_ARGV;
		(*str)[*i + 1] = ' ';
	}
	if (!(data->quotation || data->quotation_signle) &&
		!ft_strncmp((*str) + *i, ">>", 2))
	{
		delete_symbols(str, *i);
		(*str)[*i] = CODE_REDIRECT_SQUARE;
	}
}

void	shielding_two(t_data *data, t_env *env, char **str, int *i)
{
	if ((data->slash && (!data->quotation_signle && !data->quotation)) ||
		(data->slash && data->quotation &&
		((*str)[*i + 1] == '$' || (*str)[*i + 1] == '\"'
		|| (*str)[*i + 1] == '\\')))
	{
		delete_symbols(str, *i);
		replace_symbols(str, *i);
	}
	if (data->dolar && !data->quotation_signle)
	{
		shielding_dolar(env, str, *i + 1);
		check_symbols(data, str, i);
		if ((*str)[*i] == '$' || (*str)[*i] == '\'' || (*str)[*i] == '\"')
			(*i)--;
	}
	if (data->quotation || data->quotation_signle)
		replace_symbols(str, *i);
}

int		shielding(t_env *env, char **str)
{
	t_data	data;
	int		i;

	i = -1;
	init_data(&data);
	while ((*str)[++i])
	{
		shielding_one(&data, str, &i);
		check_symbols(&data, str, &i);
		shielding_two(&data, env, str, &i);
	}
	return (data.quotation || data.quotation_signle);
}
