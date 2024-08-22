/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:59:32 by amoty             #+#    #+#             */
/*   Updated: 2024/08/22 21:15:12 by tonio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>


int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i;
 
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
	{
		i++;
		write_arg(format[i++], args);
	}
	else
		write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (i);
}

void    write_arg(const char ch, va_list args)
{
        if (ch == 'c')
        	func_c(va_arg(args, int));
	if (ch == 's')
		func_s(va_arg(args, char *));
	if (ch == 'p')
		func_p(va_arg(args, void *));
	if (ch == 'd')
		func_d(va_arg(args, int));
	if (ch == 'i')
		func_i(va_arg(args, int));
	if (ch == 'u')
		func_u(va_arg(args, unsigned int));
	if (ch == 'x')
		func_x(va_arg(args, unsigned int));
	if (ch == 'X')
		func_X(va_arg(args, unsigned int));
        return ;
}

int	main()
{
	unsigned int kaka = 15;
	int nega = -123;
	int dd = 129392;
	int x = 42;
	int *p = &x;
	ft_printf("Bonjour %c \n", 'L');
	ft_printf("Bonjour %s comment ca va\n", "Tonio");
	ft_printf("L'adresse de x est : %p \n", (void *)p);
	ft_printf("ouais la miff c comment %d \n",dd );
	ft_printf("ouais la miff c comment %i \n",dd );
	ft_printf("%u \n", kaka);
	printf("%u\n ", kaka);
	ft_printf("ouais la miff c comment %x \n",dd );
	printf("ouais la miff c comment %x \n",dd );
	ft_printf("ouais la miff c comment %X \n",dd );
	printf("ouais la miff c comment %X \n",dd );
}
