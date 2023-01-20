/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:44:04 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/02 18:44:07 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr(int n, char *str)
{
	if (n == -2147483648)
	{
		ft_putnbr(147483648, str);
		ft_putnbr(2, str - 9);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putnbr(n / 10, str - 1);
	*str = '0' + n % 10;
}

char			*ft_itoa(int n)
{
	int		size;
	int		copy;
	char	*new;

	copy = n;
	size = 0;
	while (copy)
	{
		copy /= 10;
		size++;
	}
	if (n <= 0)
		size++;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	*(new + size) = '\0';
	if (n < 0)
		*new = '-';
	ft_putnbr(n, (new + --size));
	return (new);
}
