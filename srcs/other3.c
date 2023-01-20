/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:22 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:24 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	delete_symbols(char **str, int i)
{
	while ((*str)[i + 1])
	{
		(*str)[i] = (*str)[i + 1];
		i++;
	}
	(*str)[i] = (*str)[i + 1];
}

void	check_symbols(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '\"' && !data->quotation_signle)
	{
		delete_symbols(str, *i);
		data->quotation = !data->quotation;
		if ((*str)[*i] == '\'' || (*str)[*i] == '\"')
			check_symbols(data, str, i);
	}
	if ((*str)[*i] == '\'' && !data->quotation)
	{
		delete_symbols(str, *i);
		data->quotation_signle = !data->quotation_signle;
		if ((*str)[*i] == '\'' || (*str)[*i] == '\"')
			check_symbols(data, str, i);
	}
	data->dolar = (*str)[*i] == '$';
	data->slash = (*str)[*i] == '\\';
}

void	replace_semicolon(char *line)
{
	int quotation;
	int quotation_single;
	int i;

	i = 0;
	quotation = 0;
	quotation_single = 0;
	while (line[i])
	{
		if (line[i] == '\"' && !quotation_single)
			quotation = !quotation;
		if (line[i] == '\'' && !quotation)
			quotation = !quotation_single;
		if (line[i] == '\\' && line[i + 1] == ';')
			line[i + 1] = CODE_SEMICOLON;
		if (line[i] == '\\' && line[i + 1] == '<')
			line[i + 1] = CODE_BACK_REDIRECT;
		i++;
	}
}
