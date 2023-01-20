/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:45:44 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:45:46 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_env(t_env *env, char **envp)
{
	int	i;

	i = -1;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_slash);
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "HOME=", 5))
			env->home = ft_strdup(envp[i] + 5);
		else if (!ft_strncmp(envp[i], "PATH=", 5))
			env->path = ft_split(envp[i] + 5, ':');
		else if (!ft_strncmp(envp[i], "OLDPWD=", 7))
			envp[i][6] = '\0';
	}
	env->size_envp = i;
	env->envp = copy_mas(envp, env->size_envp, NULL);
	env->fd_write = dup(1);
	env->fd_read = dup(0);
}
