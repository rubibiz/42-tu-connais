/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:45:56 by amoty             #+#    #+#             */
/*   Updated: 2024/08/22 21:24:18 by tonio            ###   ########.fr       */
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

void	func_d(int i)
{
	int	j;
	char *str;

	j = 0;
	str = ft_itoa(i);
	while(str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	return ;
}

void	func_i(int i)
{
	int	j;
	char *str;

	j = 0;
	str = ft_itoa(i);
	while(str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	return ;
}
static size_t	count_size(unsigned int nb)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*printf_itoa(unsigned int n)
{
	size_t	size;
	char	*str;

	size = count_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
void func_u(unsigned int i)
{
	unsigned int j;
    char *str;

    j = 0;
    str = printf_itoa(i); 
    if (str == NULL) {
        return;
    }
    
    while (str[j]) {
        write(1, &str[j], 1);
        j++;
    }

    free(str);
}
static size_t hex_size(unsigned int n) 
{
    size_t size ;

	size = 0;
    if (n == 0) return 1;
    while (n) {
        n /= 16;
        size++;
    }
    return (size);
}

char *my_itoa_hex(unsigned int n) 
{
    size_t	size; 
	char	*str;
	const char	*hex_chars;

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
	hex_chars= "0123456789abcdef";
    while (n > 0) 
	{
        str[--size] = hex_chars[n % 16];
        n /= 16;
    } 
    return (str);
}

void	func_x(unsigned int i)
{
	char	*str;
	unsigned int	j;

	j = 0;
	str = my_itoa_hex(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
	return ;
}
char *my_itoa_hexUP(unsigned int n) 
{
    size_t	size; 
	char	*str;
	const char	*hex_chars;

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
	hex_chars= "0123456789ABCDEF";
    while (n > 0) 
	{
        str[--size] = hex_chars[n % 16];
        n /= 16;
    } 
    return (str);
}

void	func_X(unsigned int i)
{
	char	*str;
	unsigned int	j;

	j = 0;
	str = my_itoa_hexUP(i);
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
	return ;
}