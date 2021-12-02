SRCS =	main.c \
		philo_utils.c
		
OBJS = ${SRCS:.c=.o}
NAME = philo
THREADS = -pthread
CC = gcc
RM = rm -f

.c.o:
		${CC} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(CC) ${THREADS} -fsanitize=address -g3 ${OBJS} -o ${NAME}
# COMPILAR MAC $(CC) -fsanitize=address -g -L libft/ -lft ${OBJS} -o ${NAME}
# COMPILAR LINUX $(CC) -fsanitize=address -g -o ${NAME} ${OBJS} -lz -L libft/ -lft -lm

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME}

leaks:		${OBJS}
			$(CC) -g3  ${OBJS} -o ${NAME}

re:			fclean all

.PHONY:		re all clean fclean leaks