/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:49 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:51 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ctrl_c(int sig)
{
	write(1, "\b\b  \b\b", 6);
	if (g_flag_start)
	{
		g_flag_errno = 130;
	}
	else
	{
		errno = 1;
		ft_putstr_fd("\n︻┻┳══━一 ", 1);
	}
}

void	ctrl_slash(int sig)
{
	write(1, "\b\b  \b\b", 6);
	if (g_flag_start)
	{
		g_flag_errno = 131;
		ft_putendl_fd("^\\Quit: 3", 1);
	}
}
