/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoty <amoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:30:57 by amoty             #+#    #+#             */
/*   Updated: 2024/09/19 02:29:29 by amoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd)
{
    char    *buff;
    char    *stock;
    int     i;
    int     line;
    int     end;

    i = 0;
    line = 0;
    while(end != 0)
    {
        end = read(fd ,buff, 5);
        stock = buff;
        while(stock[i])
        {
            if(stock[i] == '\n')
            {
                line++;
                return(stock);
            }
            i++;
        }
    }
}

int main()
{
    int caca = open("texto.txt", O_RDONLY);
    printf("la ligne actuelle est %s\n", get_next_line(caca));
}