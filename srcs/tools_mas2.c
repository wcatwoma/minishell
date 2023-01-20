/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mas2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:15 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:47:18 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	replace_line(char *mas, char old, char ch)
{
	int		k;

	k = -1;
	while (mas[++k])
	{
		if (mas[k] == old)
			mas[k] = ch;
	}
}

void	replace_mas(char **mas, char old, char ch)
{
	int		i;
	int		k;

	i = -1;
	while (mas[++i])
		replace_line(mas[i], old, ch);
}
