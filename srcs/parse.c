/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:27 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:29 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	branching(t_env *env, char **commands)
{
	if (!ft_strcmp(*commands, "echo"))
		replace_mas(commands, CODE_ARGV, ' ');
	else
		replace_mas(commands, CODE_ARGV, '\0');
	if (!ft_strcmp(*commands, "exit"))
		ft_exitfunc(env, commands + 1);
	else if (!ft_strcmp(*commands, "cd"))
		ft_cd(env, commands + 1);
	else if (!ft_strcmp(*commands, "echo"))
		ft_echo(env, commands + 1);
	else if (!ft_strcmp(*commands, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(*commands, "export"))
		ft_export(env, commands + 1);
	else if (!ft_strcmp(*commands, "unset"))
		ft_unset(env, commands + 1);
	else if (!ft_strcmp(*commands, "env"))
		ft_env(env);
	else
		ft_other(env, commands);
	if (env->flag_exit_2)
		exit(errno);
}

void	start_command(t_env *env, char *str)
{
	char	**mas;
	char	*trim;

	replace_line(str, CODE_REDIRECT, '>');
	replace_line(str, CODE_BACK_REDIRECT, '<');
	replace_line(str, CODE_SEMICOLON, ';');
	trim = ft_strtrim(str, " ");
	mas = ft_split(trim, ' ');
	free(trim);
	replace_mas(mas, CODE_SPACE, ' ');
	errno = 0;
	branching(env, mas);
	free_mas(mas);
	if (env->flag_exit)
		ft_exit(env, errno);
}

void	start_back_redirect(t_env *env, char **str)
{
	char	**mas;
	int		count;
	int		fd;

	if (*str && **str == '<')
		*str = ft_strjoin(ft_strdup(" "), *str);
	mas = ft_split(*str, '<');
	count = ft_maslen(mas);
	skipping_fd(env, mas, count);
	if (mas[0])
		start_command(env, mas[0]);
	free_mas(mas);
}

void	start_redirect(t_env *env, char *str)
{
	int		fd;
	int		code_open;
	char	*sign;
	char	*command;

	str = ft_strtrim(str, " ");
	code_open = 0;
	if ((sign = search_redirect(str)))
	{
		sign = skipping_redirect(&code_open, str, sign, &command);
		code_open = code_open ? code_open : O_TRUNC;
		check_path(&command, sign);
		fd = open(sign, O_CREAT | O_WRONLY | code_open, ~0);
		if (*command)
			dup2(fd, 1);
		start_back_redirect(env, &command);
		close(fd);
		dup2(env->fd_write, 1);
		free(command);
	}
	else
		start_back_redirect(env, &str);
	free(str);
}

void	start_section(t_env *env, char **section)
{
	int		size;
	char	**mas;
	char	*trim;

	env->fd = -1;
	env->flag_exit = 0;
	if (shielding(env, section))
		return ;
	trim = ft_strtrim(*section, " ");
	mas = ft_split(trim, '|');
	free(trim);
	replace_mas(mas, CODE_PIPE, '|');
	size = ft_maslen(mas);
	env->count_pipe = size;
	if (*mas && size > 1)
		start_pipe(env, mas, size);
	else if (*mas)
	{
		env->flag_exit_2 = 0;
		start_redirect(env, *mas);
	}
	free_mas(mas);
}
