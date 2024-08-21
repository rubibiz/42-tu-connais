/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:59:32 by amoty             #+#    #+#             */
/*   Updated: 2024/08/20 16:44:41 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


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
        return ;
}

int	main()
{
	int x = 42;
	int *p = &x;
	ft_printf("Bonjour %c \n", 'L');
	ft_printf("Bonjour %s comment ca va\n", "Tonio");
	ft_printf("L'adresse de x est : %p", (void *)p);
}
