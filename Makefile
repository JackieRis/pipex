# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:26:21 by tnguyen-          #+#    #+#              #
#    Updated: 2022/01/16 01:47:47 by tnguyen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= main.c ft_strlen.c ft_putstr_fd.c ft_strjoin.c ft_memcpy.c utils.c \
	ft_split.c ft_calloc.c ft_bzero.c ft_strlcpy.c ft_memset.c clean.c \
	ft_strncmp.c process.c close.c get_next_line.c get_next_line_utils.c \
	ft_memcmp.c

OBJ	= ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra -I.

all: ${NAME}

%.o:%.c pipex.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJ}
	$(CC) ${FLAGS} $(OBJ) -o $(NAME)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
