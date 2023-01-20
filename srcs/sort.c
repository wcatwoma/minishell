/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:46:53 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:46:55 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(int *one, int *two)
{
	int		tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

int		is_greater(t_env *env, int *sort, int k)
{
	char	*str_one;
	char	*str_two;
	int		size_key_1;
	int		size_key_2;

	str_one = env->envp[sort[k]];
	str_two = env->envp[sort[k + 1]];
	size_key_1 = ft_strchr(str_one, '=') - str_one;
	size_key_2 = ft_strchr(str_two, '=') - str_two;
	size_key_1 = size_key_2 < size_key_1 ? size_key_2 : size_key_1;
	return (ft_strncmp(str_one, str_two, size_key_1) > 0 ? 1 : 0);
}

void	sort_env(t_env *env, int *sort)
{
	int		i;
	int		k;

	i = -1;
	while (env->envp[++i])
		sort[i] = i;
	i = -1;
	while (++i < env->size_envp - 1)
	{
		k = -1;
		while (++k < env->size_envp - i - 1)
		{
			if (is_greater(env, sort, k))
				ft_swap(&sort[k], &sort[k + 1]);
		}
	}
}
