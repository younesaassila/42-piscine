# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:15:55 by yaassila          #+#    #+#              #
#    Updated: 2022/07/23 12:34:55 by yaassila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
INCS	= includes
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= -rcs
RM		= rm -rf

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}
	ranlib ${NAME}

srcs/%.o: srcs/%.c
	${CC} ${CFLAGS} -I${INCS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
