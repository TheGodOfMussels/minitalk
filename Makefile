# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 17:31:34 by dimolin2          #+#    #+#              #
#    Updated: 2023/01/26 17:31:37 by dimolin2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft
	
client: client.o libft
	$(CC) -o $@ $< -Llibft -lft
	
%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
libft:
	make -C libft
	
clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a
	
re: fclean all

 .PHONY: all bonus libft clean fclean re
