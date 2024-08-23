/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:36 by amoty             #+#    #+#             */
/*   Updated: 2024/06/06 21:42:25 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (n < size - 1 && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (i);
}
