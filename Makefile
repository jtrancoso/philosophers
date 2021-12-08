SRCS =	main.c \
		philo_utils.c \
		philo_utils2.c \
		init_philo.c \
		eating_loop.c
		
OBJS = ${SRCS:.c=.o}
NAME = philo
THREADS = -pthread
CFLAGS = -Werror -Wall -Wextra
CC = gcc
RM = rm -f

.c.o:
		${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(CC) -g3 ${OBJS} -o ${NAME} -pthread
# COMPILAR MAC $(CC) -fsanitize=address -g ${OBJS} -o ${NAME}
# COMPILAR LINUX $(CC) -fsanitize=address -g -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME}

leaks:		${OBJS}
			$(CC) ${OBJS} -o ${NAME} -pthread

re:			fclean all

.PHONY:		re all clean fclean leaks