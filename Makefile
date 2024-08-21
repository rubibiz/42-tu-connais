# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoty <amoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:17:44 by amoty             #+#    #+#              #
#    Updated: 2024/08/10 18:15:24 by amoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = 




OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I> -o $@ -c $? $(CFLAGS)

all : $(NAME)

clean : 
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean
