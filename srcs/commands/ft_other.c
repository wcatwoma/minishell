/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:49:54 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:49:56 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

int		edit_cmd_execve(t_env *env, char **option)
{
	int		i;
	int		out_excv;
	char	*tmp;
	char	*path_command;

	i = -1;
	out_excv = -1;
	while (out_excv == -1 && env->path && env->path[++i])
	{
		tmp = ft_strjoin(ft_strdup(env->path[i]), ft_strdup("/"));
		path_command = ft_strjoin(tmp, ft_strdup(*option));
		out_excv = execve(path_command, option, env->envp);
		free(path_command);
	}
	return (out_excv);
}

void	ft_other(t_env *env, char **option)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (env->fd >= 0)
			dup2(env->fd, 0);
		if (env->fd == -2)
			exit(1);
		if (ft_strchr(*option, '/'))
			errno = execve(*option, option, env->envp);
		else
			errno = edit_cmd_execve(env, option);
		if (errno == -1 && ft_strchr(*option, '/'))
			ft_error(*option, NULL, ERROR_NO_FILE, env->fd_write);
		else if (errno == -1)
			ft_error(*option, NULL, presence_env(env, "PATH") == -1 ?
					ERROR_NO_FILE : ERROR_NOT_FOUND, env->fd_write);
		exit(errno);
	}
	else
		waitpid(pid, &status, 0);
	close(env->fd);
	errno = WEXITSTATUS(status);
}
