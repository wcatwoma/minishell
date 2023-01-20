/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:34 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:36 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	edit_fd(char **commands, int **pipefds, int i)
{
	if (i > 0)
	{
		close(pipefds[i - 1][1]);
		dup2(pipefds[i - 1][0], 0);
	}
	if (commands[i + 1] != NULL)
	{
		close(pipefds[i][0]);
		dup2(pipefds[i][1], 1);
	}
}

void	wait_child(t_env *env, pid_t *children, int **pipefds, int size)
{
	int		i;
	int		status;

	i = -1;
	while (++i < size)
	{
		waitpid(children[i], &status, 0);
		if (i + 1 != size && pipefds[i])
			free(pipefds[i]);
		if (env->flag_exit)
			exit(WEXITSTATUS(status));
	}
	free(pipefds);
	free(children);
}

void	return_default_fd(t_env *env, int **pipefds, int i)
{
	if (i > 0)
	{
		close(pipefds[i - 1][0]);
		close(pipefds[i - 1][1]);
		dup2(1, env->fd_write);
		dup2(0, env->fd_read);
	}
}

void	add_pipe(char **commands, int **pipefds, int i)
{
	if (commands[i + 1] != NULL)
	{
		pipefds[i] = (int*)malloc(sizeof(int) * 2);
		pipe(pipefds[i]);
	}
}

void	start_pipe(t_env *env, char **commands, int size)
{
	int		i;
	pid_t	*children;
	int		**pipefds;

	children = (pid_t*)malloc(sizeof(pid_t) * size);
	pipefds = (int**)malloc(sizeof(int*) * size);
	i = -1;
	while (commands[++i])
	{
		add_pipe(commands, pipefds, i);
		if ((children[i] = fork()) == 0)
		{
			env->flag_exit = 0;
			edit_fd(commands, pipefds, i);
			env->flag_exit_2 = 1;
			start_redirect(env, commands[i]);
		}
		return_default_fd(env, pipefds, i);
	}
	wait_child(env, children, pipefds, size);
}
