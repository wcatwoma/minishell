/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:45:30 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:45:33 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(t_env *env, int code_error)
{
	free(env->home);
	if (env->path)
		free_mas(env->path);
	if (env->envp)
		free_mas(env->envp);
	exit(code_error);
}
