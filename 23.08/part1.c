/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:45:56 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 18:17:53 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	func_c(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	func_s(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_hex_digit(char *buffer, int *i, int hex_digit)
{
	if (hex_digit < 10)
	{
		buffer[(*i)++] = '0' + hex_digit;
	}
	else
	{
		buffer[(*i)++] = 'a' + (hex_digit - 10);
	}
	return (1);
}

int	process_address(uintptr_t address, char *buffer, int *i)
{
	int	shift;
	int	hex_digit;
	int	count;

	shift = (sizeof(uintptr_t) * 8) - 4;
	count = 0;
	while (((address >> shift) & 0xF) == 0 && shift > 0)
	{
		shift -= 4;
	}
	while (shift >= 0)
	{
		hex_digit = (address >> shift) & 0xF;
		count += print_hex_digit(buffer, i, hex_digit);
		shift -= 4;
	}
	return (count);
}

int	func_p(void *ptr)
{
	uintptr_t	address;
	char		buffer[20];
	int			i;
	int			count;

	address = (uintptr_t)ptr;
	i = 0;
	buffer[i++] = '0';
	buffer[i++] = 'x';
	count = 2;
	if (address == 0)
	{
		buffer[i++] = '0';
		count++;
	}
	else
	{
		count += process_address(address, buffer, &i);
	}
	buffer[i] = '\0';
	write(1, buffer, i);
	return (count);
}
