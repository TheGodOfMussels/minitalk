# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:33:40 by dimolin2          #+#    #+#              #
#    Updated: 2022/10/17 19:33:44 by dimolin2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FILES_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstdelone.c ft_lstclear.c ft_lstadd_back.c \
	ft_lstiter.c ft_lstmap.c
OBJECTS=$(FILES:.c=.o)
OBJECTS_BONUS=$(FILES_BONUS:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror 
NAME=libft.a

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -c ${FILES}
	ar -rsv libft.a ${OBJECTS}

bonus:
	${CC} ${CFLAGS} -c ${FILES_BONUS}
	ar -rsv libft.a ${OBJECTS_BONUS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}
	
re:	fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus
