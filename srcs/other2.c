/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:14 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:17 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_space(int ch)
{
	if (ch == ' ')
		return (1);
	return (0);
}

char	*search_redirect(char *str)
{
	char *redirect;
	char *redirect_square;

	redirect = ft_strchr(str, '>');
	redirect_square = ft_strchr(str, CODE_REDIRECT_SQUARE);
	if (!redirect)
		redirect = redirect_square;
	if (redirect && redirect_square && redirect_square < redirect)
		redirect = redirect_square;
	return (redirect);
}

void	kost(char *str, char **edit_str, char *tmp, char *space)
{
	str = ft_strjoin(ft_substr(*edit_str, 0, str - *edit_str), tmp);
	str = ft_strjoin(str, ft_substr(space, 0, ft_strlen(space)));
	free(*edit_str);
	*edit_str = str;
}

void	init_data(t_data *data)
{
	data->slash = 0;
	data->quotation = 0;
	data->quotation_signle = 0;
	data->dolar = 0;
}

int		ft_isspace(int ch)
{
	if (ch == ' ')
		return (1);
	return (0);
}
