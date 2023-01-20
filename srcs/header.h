/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:45:37 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:45:40 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1
# define ERROR_EXPORT 1
# define ERROR_UNSET_ARG 2
# define ERROR_UNSET_NAME 3
# define ERROR_NAME 4
# define ERROR_NOT_FOUND 5
# define ERROR_NO_FILE 6
# define ERROR_MANY_ARGV 7
# define ERROR_NUMERIC_ARGV 8
# define ERROR_NOT_SET 9
# define ERROR_TOKEN 10
# define CODE_SPACE 1
# define CODE_SEMICOLON 2
# define CODE_REDIRECT 3
# define CODE_BACK_REDIRECT 4
# define CODE_REDIRECT_SQUARE 5
# define CODE_PIPE 6
# define CODE_ARGV 7

int					g_flag_start;
int					g_flag_errno;

typedef struct		s_env
{
	char			*home;
	char			**path;
	char			**envp;
	int				size_envp;
	int				fd;
	int				fd_read;
	int				fd_write;
	int				flag_exit;
	int				flag_exit_2;
	int				count_pipe;
}					t_env;

typedef struct		s_token
{
	size_t			one;
	size_t			two;
	size_t			three;
	size_t			four;
}					t_token;

typedef struct		s_data
{
	int				slash;
	int				quotation;
	int				quotation_signle;
	int				dolar;
}					t_data;

int					ft_strlen(char *str);
char				*ft_strjoin(char *one, char *two);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(char const *s);
int					get_next_line(int fd, char **line);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_strcmp(char *str1, char *str2);
int					ft_strncmp(char *str1, char *str2, size_t n);
char				**ft_split(char const *s, char ch);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strdup(char const *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
void				ft_echo(t_env *env, char **commands);
void				ft_cd(t_env *env, char **commands);
void				ft_export(t_env *env, char **option);
void				ft_unset(t_env *env, char **option);
void				ft_other(t_env *env, char **command);
void				ft_pwd(void);
void				ft_env(t_env *env);
void				ft_exitfunc(t_env *env, char **option);
void				skipping_spaces(char **str);
char				*skipping_redirect(int *code_open,
char				*str, char *sign, char **command);
void				sort_env(t_env *env, int *sort);
void				add_env(t_env *env, char **variables);
void				free_mas(char **mas);
char				**copy_mas(char **mas, int count_add, char *str);
char				*replace_element(char *str, char *two);
char				**add_element_mas(char **mas, int count_add, char *str);
char				**delete_element_mas(char **mas, int count_add, char *str);
void				sort_env(t_env *env, int *sort);
void				ft_error(char *message,
char				*other, int code, int fd_write);
int					ft_isalnum(int ch);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_isalpha_underline(int ch);
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
int					check(char *str, int (*func)(int), char ch);
int					check_env(t_env *env, char *str);
char				*get_value_env(t_env *env, char *str);
int					shielding(t_env *env, char **str);
void				replace_mas(char **mas, char old, char ch);
void				replace_line(char *mas, char old, char ch);
int					ft_atoi(const char *str);
void				start_pipe(t_env *env, char **commands, int size);
void				init_env(t_env *env, char **envp);
void				minishell(t_env *env, char *line);
int					check_line(t_env *env, char *line);
void				start_command(t_env *env, char *str);
void				start_redirect(t_env *env, char *str);
int					presence_env(t_env *env, char *str);
int					ft_strcmp_env(char *key, char *str);
int					ft_maslen(char **mas);
void				skipping_fd(t_env *env, char **mas, int count);
void				start_section(t_env *env, char **section);
void				ctrl_c(int sig);
void				ctrl_slash(int sig);
void				ft_exit(t_env *env, int code_error);
int					is_space(int ch);
char				*search_redirect(char *str);
void				check_path(char **command, char *path);
int					ft_isspace(int ch);
int					ft_issemicolon(int ch);
void				kost(char *str, char **edit_str, char *tmp, char *space);
size_t				check_token(char *line, char ch);
int					check_value_env(char *str);
void				init_data(t_data *data);
void				delete_symbols(char **str, int i);
void				check_symbols(t_data *data, char **str, int *i);
void				replace_semicolon(char *line);

#endif
