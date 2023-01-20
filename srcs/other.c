/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:09 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:11 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	skipping_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	check_path(char **command, char *path)
{
	while (*path)
	{
		if (*path == ' ')
		{
			*path = '\0';
			*command = ft_strjoin(*command, ft_strdup(++path));
			return ;
		}
		path++;
	}
}

char	*skipping_redirect(int *code_open, char *str, char *sign,
char **command)
{
	char	*tmp;
	char	*path;
	int		fd;

	tmp = NULL;
	if (*sign == CODE_REDIRECT_SQUARE)
		*code_open = O_APPEND;
	*command = ft_substr(str, 0, sign++ - str);
	skipping_spaces(&sign);
	while ((tmp = search_redirect(sign)))
	{
		*code_open = *tmp == CODE_REDIRECT_SQUARE ? O_APPEND : 0;
		*tmp = '\0';
		path = ft_strtrim(sign, " ");
		check_path(command, path);
		fd = open(path, O_CREAT, ~0);
		free(path);
		close(fd);
		sign = tmp + 1;
		skipping_spaces(&sign);
	}
	skipping_spaces(&sign);
	return (sign);
}

void	skipping_fd(t_env *env, char **mas, int count)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 1;
	while ((count > 1 && i < count))
	{
		tmp = ft_strtrim(mas[i], " ");
		check_path(&mas[0], tmp);
		fd = open(tmp, O_RDONLY);
		if (fd == -1)
		{
			env->fd = -2;
			ft_error(tmp, "", ERROR_NAME, env->fd_write);
			return ;
		}
		free(tmp);
		if (i == count - 1)
			env->fd = fd;
		else
			close(fd);
		i++;
	}
}

int		ft_maslen(char **mas)
{
	int i;

	i = 0;
	while (mas[i])
		i++;
	return (i);
}
