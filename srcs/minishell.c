/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:03 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/09/18 18:58:14 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_edit_env(t_env *env)
{
	char *str;

	str = get_value_env(env, "PATH");
	if (env->path)
		free_mas(env->path);
	if (!str)
	{
		env->path = NULL;
		return ;
	}
	env->path = ft_split(str, ':');
	free(str);
}

void	minishell(t_env *env, char *line)
{
	int		i;
	char	**commands;

	g_flag_start = 1;
	if (check_line(env, line))
		return ;
	commands = ft_split(line, ';');
	replace_mas(commands, CODE_SEMICOLON, ';');
	i = -1;
	while (commands[++i])
	{
		check_edit_env(env);
		start_section(env, &commands[i]);
	}
	free_mas(commands);
}

void	analysis_signal(t_env *env, char **line, int code, int *code_2)
{
	if (!code && !**line && *code_2)
	{
		ft_putendl_fd("exit", 1);
		ft_exit(env, errno);
	}
	if (code)
	{
		*code_2 = 1;
		minishell(env, *line);
	}
	else
		*code_2 = 0;
	if (code)
	{
		free(*line);
		*line = ft_strdup("");
	}
}

void	work_flag(void)
{
	g_flag_start = 0;
	if (g_flag_errno)
		errno = g_flag_errno;
	g_flag_errno = 0;
}

int		main(int argc, char **argv, char **envp)
{
	t_env	env;
	int		code;
	int		code_2;
	char	*line;

	code_2 = 1;
	code = 1;
	line = NULL;
	init_env(&env, envp);
	while (1)
	{
		check_edit_env(&env);
		if (line != NULL && code)
		{
			free(line);
			line = ft_strdup("");
		}
		work_flag();
		if (code)
			ft_putstr_fd("SWAG ", 1);
		if ((code = get_next_line(0, &line)) < 0)
			return (-1);
		analysis_signal(&env, &line, code, &code_2);
	}
	return (0);
}
