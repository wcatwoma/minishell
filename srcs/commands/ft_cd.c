/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:44 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:47:46 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	update_value_env(t_env *env, char *key, char *value)
{
	char	**mas;

	mas = (char**)malloc(sizeof(char*) * 2);
	mas[0] = ft_strjoin(ft_strdup(key), ft_strdup(value));
	mas[1] = NULL;
	ft_export(env, mas);
	free(mas[0]);
	free(mas);
}

void	ft_cd(t_env *env, char **option)
{
	char	*str;
	char	dir[300];

	str = NULL;
	getcwd(dir, 300);
	if (!*option || ((int)*option - 1 != -1 && **option == '\0'))
		str = get_value_env(env, "HOME");
	else if (!ft_strncmp(*option, "~", 1))
		str = ft_strjoin(ft_strdup(env->home), ft_strdup(*option + 1));
	else
		str = ft_strdup(*option);
	if (!str || !*str)
		ft_error("cd", "HOME", ERROR_NOT_SET, env->fd_write);
	else if (chdir(str) < 0)
		ft_error(*option, "cd: ", ERROR_NAME, env->fd_write);
	else if (presence_env(env, "PWD") != -1)
	{
		update_value_env(env, "OLDPWD=", dir);
		getcwd(dir, 300);
		update_value_env(env, "PWD=", dir);
	}
	free(str);
}
