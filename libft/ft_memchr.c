/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:03:39 by amoty             #+#    #+#             */
/*   Updated: 2024/06/06 22:25:30 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
