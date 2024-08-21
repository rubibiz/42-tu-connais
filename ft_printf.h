/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:39:57 by amoty             #+#    #+#             */
/*   Updated: 2024/08/20 16:41:49 by amoty            ###   ########.fr       */
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

#endif
