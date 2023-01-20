/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:42:23 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:42:25 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *one, const void *two, size_t num)
{
	while (num--)
		if (*((unsigned char*)one++) != *((unsigned char*)two++))
			return (*((unsigned char*)one - 1) - *((unsigned char*)two - 1));
	return (0);
}
