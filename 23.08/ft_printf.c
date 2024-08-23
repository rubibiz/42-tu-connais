/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:59:32 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 18:29:54 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int write_arg(const char ch, va_list args)
{
    int written;

    written = 0;    
    if (ch == 'c')
        written = func_c(va_arg(args, int));
    else if (ch == 's')
        written = func_s(va_arg(args, char *));
    else if (ch == 'p')
        written = func_p(va_arg(args, void *));
    else if (ch == 'd' || ch == 'i')
        written = func_d(va_arg(args, int));
    else if (ch == 'u')
        written = func_u(va_arg(args, unsigned int));
    else if (ch == 'x')
        written = func_x(va_arg(args, unsigned int));
    else if (ch == 'X')
        written = func_xx(va_arg(args, unsigned int));
    else if (ch == '%')
    {
        write(1, "%", 1);
        written = 1;
    }    
    return (written);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;
    va_start(args, format);
    
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += write_arg(format[i], args);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);   
    return (count);
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
