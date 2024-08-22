/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:39:57 by amoty             #+#    #+#             */
/*   Updated: 2024/08/22 21:15:15 by tonio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
void    write_arg(const char ch, va_list args);
void    func_c(const char c);
void	func_s(const char *str);
void	func_p(void *ptr);
void	print_hex_digits(char *buffer, int *i, int hex_digit);
void	process_address(uintptr_t address, char *buffer, int *i);
void    func_d(int i);
void    func_i(int i);
void	func_u(unsigned int i);
char	*printf_itoa(unsigned int n);
static size_t	count_size(unsigned int nb);
void	func_x(unsigned int i);
static size_t hex_size(unsigned int n);
char *my_itoa_hex(unsigned int n);
char *my_itoa_hexUP(unsigned int n);
void	func_X(unsigned int i);



#endif
