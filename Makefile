SRC	=	src/ft_atoi.c src/ft_itoa.c src/init.c src/main.c src/states.c src/time.c src/live_like_a_philo.c src/errors.c src/end.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

RM	=	rm -f
CC	=	clang
CFLAGS	=	-Wall -Werror -Wextra -pthread

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)

all	:	$(NAME)


clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
