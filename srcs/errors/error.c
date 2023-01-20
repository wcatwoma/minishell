/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:35 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:47:38 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	ft_error_one(char *message, char *other, int code, int fd_write)
{
	if (code == ERROR_EXPORT)
	{
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(other, fd_write);
		ft_putstr_fd(": `", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd("': not a valid identifier", fd_write);
	}
	else if (code == ERROR_UNSET_ARG)
	{
		ft_putendl_fd("unset: not enough arguments", fd_write);
	}
	else if (code == ERROR_NAME)
	{
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(other, fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd(": No such file or directory", fd_write);
	}
}

void	ft_error_two(char *message, char *other, int code, int fd_write)
{
	if (code == ERROR_NOT_FOUND)
	{
		errno = 127;
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd(": command not found", fd_write);
	}
	else if (code == ERROR_NO_FILE)
	{
		errno = 127;
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd(": No such file or directory", fd_write);
	}
	else if (code == ERROR_MANY_ARGV)
	{
		ft_putendl_fd(message, 1);
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd(": too many arguments", fd_write);
	}
}

void	ft_error_three(char *message, char *other, int code, int fd_write)
{
	if (code == ERROR_NUMERIC_ARGV)
	{
		errno = 255;
		ft_putendl_fd(message, 1);
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putstr_fd(": ", fd_write);
		ft_putstr_fd(other, fd_write);
		ft_putendl_fd(": numeric argument required", fd_write);
	}
	else if (code == ERROR_NOT_SET)
	{
		ft_putstr_fd("bash: ", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putstr_fd(": ", fd_write);
		ft_putstr_fd(other, fd_write);
		ft_putendl_fd(" not set", fd_write);
	}
	else if (code == ERROR_TOKEN && (errno = 258))
	{
		ft_putstr_fd("bash: syntax error near", fd_write);
		ft_putstr_fd(" unexpected token `", fd_write);
		ft_putstr_fd(message, fd_write);
		ft_putendl_fd("'", fd_write);
	}
}

void	ft_error(char *message, char *other, int code, int fd_write)
{
	errno = 1;
	ft_error_one(message, other, code, fd_write);
	ft_error_two(message, other, code, fd_write);
	ft_error_three(message, other, code, fd_write);
}
