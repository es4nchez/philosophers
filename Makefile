SRC	=	ft_atoi.c ft_itoa.c init.c main.c states.c time.c live_like_a_philo.c errors.c end.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

RM	=	rm -f
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g

.c.o:         
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	:	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)
													
all	:	$(NAME)

								
clean	:	
	@$(RM) $(OBJ)
											
fclean	:	clean
	@$(RM) $(NAME)
														
re	:	fclean all
												
.PHONY	:	all clean fclean re
