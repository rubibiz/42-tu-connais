/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:16:33 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 17:53:25 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	hex_size(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*my_itoa_hex(unsigned int n)
{
	size_t			size;
	char			*str;
	const char		*hex_chars;

	size = hex_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	hex_chars = "0123456789abcdef";
	while (n > 0)
	{
		str[--size] = hex_chars[n % 16];
		n /= 16;
	}
	return (str);
}

int	func_x(unsigned int i)
{
	int		j;
	char				*str;

	j = 0;
	str = my_itoa_hex(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
	return (j);
}

char	*my_itoa_hexup(unsigned int n)
{
	size_t			size;
	char			*str;
	const char		*hex_chars;

	size = hex_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	hex_chars = "0123456789ABCDEF";
	while (n > 0)
	{
		str[--size] = hex_chars[n % 16];
	n /= 16;
	}
	return (str);
}

int	func_xx(unsigned int i)
{
	unsigned int		j;
	char				*str;

	j = 0;
	str = my_itoa_hexup(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
	return (j);
}
