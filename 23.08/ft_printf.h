/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:39:57 by amoty             #+#    #+#             */
/*   Updated: 2024/08/23 17:56:34 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int		    ft_printf(const char *format, ...);
int		    write_arg(const char ch, va_list args);
int			func_c(const char c);
int			func_s(const char *str);
int			func_p(void *ptr);
int			print_hex_digits(char *buffer, int *i, int hex_digit);
int			process_address(uintptr_t address, char *buffer, int *i);
int			func_d(int i);
int			func_i(int i);
int			func_u(unsigned int i);
char		*printf_itoa(unsigned int n);
int			func_x(unsigned int i);
char		*my_itoa_hex(unsigned int n);
char		*my_itoa_hexup(unsigned int n);
int			func_xx(unsigned int i);
size_t		hex_size(unsigned int n);
size_t		count_size(unsigned int nb);

#endif
