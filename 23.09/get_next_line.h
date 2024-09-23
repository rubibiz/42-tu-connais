/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:02:51 by tonio             #+#    #+#             */
/*   Updated: 2024/09/21 22:30:04 by tonio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen2(const char *str, size_t size);
char	*ft_strdup(const char *s1, size_t nbytes, size_t line);
char    *get_next_line(int fd);
size_t	ft_strlen(char *str);







#endif