/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:45:56 by amoty             #+#    #+#             */
/*   Updated: 2024/08/20 16:39:08 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	func_c(const char c)
{
	write(1, &c, 1);
	return ;
}

void	func_s(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

void	print_hex_digit(char *buffer, int *i, int hex_digit)
{
	if (hex_digit < 10)
		buffer[(*i)++] = '0' + hex_digit;
	else
		buffer[(*i)++] = 'a' + (hex_digit - 10);
}

void	process_address(uintptr_t address, char *buffer, int *i)
{
	int	shift;
	int	hex_digit;

	shift = (sizeof(uintptr_t) * 8) - 4;
	while (((address >> shift) & 0xF) == 0 && shift > 0)
	shift -= 4;
	while (shift >= 0)
	{
		hex_digit = (address >> shift) & 0xF;
		print_hex_digit(buffer, i, hex_digit);
		shift -= 4;
	}
}

void	func_p(void *ptr)
{
	uintptr_t	address;
	char		buffer[20];
	int			i;

	address = (uintptr_t)ptr;
	i = 0;
	buffer[i++] = '0';
	buffer[i++] = 'x';
	process_address(address, buffer, &i);
	if (i == 2)
		buffer[i++] = '0';
	buffer[i] = '\0';
	write(1, buffer, i);
}
