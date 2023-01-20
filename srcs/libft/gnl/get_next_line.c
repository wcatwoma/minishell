/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:36:01 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:36:07 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_end_of_line(char **end_line, char *buf, char **tail)
{
	if (!buf)
		return (1);
	if ((*end_line = ft_strchr(buf, '\n')) != NULL)
	{
		**end_line = '\0';
		if (!(*tail = ft_strdup(*end_line + 1)))
			return (-1);
	}
	return (1);
}

int		check_tail(char **line, char **tail, char **end_line)
{
	char		*start_tail;
	int			option;

	start_tail = *tail;
	if (get_end_of_line(end_line, start_tail, tail) == -1)
		return (-1);
	if (start_tail != *tail)
		*line = ft_strjoin(*line, start_tail);
	else
		*line = ft_strjoin(*line, *tail ? *tail : ft_strdup(""));
	if (!(*line))
		return (-1);
	option = start_tail != *tail ? 1 : 0;
	if (option)
		start_tail = NULL;
	else
		*tail = NULL;
	return (1);
}

int		get_line(int fd, char **line, char **tail)
{
	char		buf[BUFFER_SIZE + 1];
	char		*end_line;
	size_t		size;

	end_line = NULL;
	size = 1;
	if (check_tail(line, tail, &end_line) == -1 || (read(fd, buf, 0) == -1))
		return (-1);
	while (!end_line && (size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[size] = '\0';
		if (get_end_of_line(&end_line, buf, tail) == -1 ||
			!(*line = ft_strjoin(*line, ft_strdup(buf))))
		{
			return (-1);
		}
	}
	return (end_line ? 1 : 0);
}

t_file	*search_node(int fd, t_file *tmp, t_file **befor_node)
{
	while (tmp)
	{
		if (tmp && tmp->fd == fd)
			break ;
		if (!(tmp->next))
			if (!(tmp->next = ft_lstnew(fd)))
				return (NULL);
		*befor_node = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static t_file	*files;
	t_file			*tmp;
	t_file			*befor_node;
	int				res;

	if (fd < 0 || !line || !(files = files ? files : ft_lstnew(fd)))
		return (-1);
	befor_node = NULL;
	if (!(tmp = search_node(fd, files, &befor_node)))
		return (-1);
	res = get_line(tmp->fd, line, &tmp->tail);
	if (befor_node != NULL && (!res || res == -1))
	{
		befor_node->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	else if (!res || res == -1)
	{
		tmp = files;
		files = files->next;
		free(tmp);
	}
	return (res);
}
