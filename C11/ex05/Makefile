# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 11:29:42 by yaassila          #+#    #+#              #
#    Updated: 2022/07/25 12:32:24 by yaassila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op
INCS	= includes
SRCS	= srcs/main.c srcs/operators.c srcs/utils.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

srcs/%.o: srcs/%.c
	${CC} ${CFLAGS} -I${INCS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
