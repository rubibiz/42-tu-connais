/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonio <tonio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:30:57 by amoty             #+#    #+#             */
/*   Updated: 2024/09/21 22:30:22 by tonio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char    *get_next_line(int fd)
{
    char    *buff;
    char    *stock;
    size_t     i;
    static int  line;
    
    i = 0;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read(fd,buff, BUFFER_SIZE);
    stock = ft_strdup(buff, BUFFER_SIZE, line);
    while(stock[i])
    {
        if(stock[i] == '\n')
        {
            line = ft_strlen(stock);
            return(stock);
        }
        i++;
    }
    line = ft_strlen(stock);
    return(stock);
}

int main()
{
    int caca = open("texto.txt", O_RDONLY);
    printf("%s\n", get_next_line(caca));

}