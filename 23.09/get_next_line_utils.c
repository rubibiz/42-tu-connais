/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:30:57 by amoty             #+#    #+#             */
/*   Updated: 2024/09/21 23:05:51 by tonio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen2(const char *str, size_t size)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0' && i < size)
		i++;
	return(i);
}

char	*ft_strdup(const char *s1, size_t nbytes, size_t line)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (nbytes + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (line > 0)
		i = line;
	while (s1[i] != '\0' && i < nbytes && s1[i] != '\n')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while(str[i])
		i++;
	return(i);
}
