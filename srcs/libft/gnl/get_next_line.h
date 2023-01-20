/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:36:11 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:36:14 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct		s_file
{
	int				fd;
	char			*tail;
	struct s_file	*next;
}					t_file;

int					ft_strlen(char *str);
char				*ft_strjoin(char *one, char *two);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(char const *s);
t_file				*ft_lstnew(int fd);
int					get_next_line(int fd, char **line);

#endif
