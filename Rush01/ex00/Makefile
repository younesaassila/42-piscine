SRC		= $(wildcard *.c)
OBJ		= ${SRC:.c=.o}
EXEC	= rush-01
CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			${CC} ${CFLAGS} -I. -o $@ -c $<

${EXEC}:	${OBJ}
			${CC} ${CFLAGS} -I. -o $@ $^

all:		${EXEC}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${EXEC}

re:			fclean all

allclean:	all clean