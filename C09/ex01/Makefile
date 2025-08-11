# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asurcouf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 21:47:02 by asurcouf          #+#    #+#              #
#    Updated: 2025/02/03 22:01:15 by asurcouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c

SRC		= ./srcs/
SRCS	= ${SRC}/ft_putchar.c ${SRC}/ft_swap.c ${SRC}/ft_putstr.c ${SRC}/ft_strlen.c ${SRC}/ft_strcmp.c

NAME	= libft.a
HEAD 	= ./includes/
OBJS	= ${SRCS:.c=.o}

RM		= rm -f
AR		= ar -rc
LIB		= ranlib

all:	${NAME}

%.o: %.c
				${CC} ${CFLAGS} -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				${LIB} ${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:		all clean fclean re
