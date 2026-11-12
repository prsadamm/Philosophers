NAME = philo

SRC = dead.c diner_action.c parsing.c philo.c main.c

OBJS = ${SRC:.c=.o}

RM = rm -f

CC = cc

CFLAGS = -pthread -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
