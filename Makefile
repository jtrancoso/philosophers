SRCS =	main.c \
		philo_utils.c \
		philo_utils2.c \
		init_philo.c \
		eating_loop.c \
		death_loop.c
		
OBJS = ${SRCS:.c=.o}
NAME = philo
THREADS = -pthread
CFLAGS = -Werror -Wall -Wextra
CC = gcc
RM = rm -f

.c.o:
		${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(CC) -g3 ${OBJS} -o ${NAME} ${THREADS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re all clean fclean