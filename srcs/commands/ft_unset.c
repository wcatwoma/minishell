/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:50:05 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:50:07 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	ft_unset(t_env *env, char **option)
{
	int		i;

	i = 0;
	while (option[i])
	{
		if (check_value_env(option[i]) || option[i][0] == '=')
		{
			ft_error(option[i], "unset", ERROR_EXPORT, env->fd_write);
			i++;
			continue ;
		}
		if (presence_env(env, option[i]) != -1)
		{
			env->envp =
			delete_element_mas(env->envp, --env->size_envp, option[i]);
		}
		i++;
	}
}
