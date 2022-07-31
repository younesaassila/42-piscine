# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:15:55 by yaassila          #+#    #+#              #
#    Updated: 2022/07/24 18:48:41 by yaassila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush-02
INCS_DIR	= includes
SRCS_DIR	= srcs
SRCS		= ${SRCS_DIR}/main.c ${SRCS_DIR}/dict_1.c ${SRCS_DIR}/dict_2.c ${SRCS_DIR}/errors.c ${SRCS_DIR}/file_utils_1.c ${SRCS_DIR}/file_utils_2.c ${SRCS_DIR}/parse_1.c ${SRCS_DIR}/parse_2.c ${SRCS_DIR}/solve_1.c ${SRCS_DIR}/solve_2.c ${SRCS_DIR}/string_utils_1.c ${SRCS_DIR}/string_utils_2.c ${SRCS_DIR}/string_utils_3.c
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

${NAME}: ${SRCS}
	${CC} ${CFLAGS} -I${INCS_DIR} ${SRCS} -o ${NAME}
	chmod +x ${NAME}

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all
