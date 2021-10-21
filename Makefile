NAME 		= pipex
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror 
SRCS		= mandatory/pipex.c
OBJS 		= $(SRCS:.c=.o)
BONUS_SRCS	= bonus/pipex.c
BONUS_OBJS 	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME):$(SRCS)
	@make -C ./mandatory
	$(CC) $(CFLAGS) $(SRCS) ./mandatory/pipex_mandatory -o $(NAME)

bonus: $(BONUS_SRCS)
		@make -C ./bonus
		$(CC) $(BONUS_SRCS) ./bonus/pipex_bonus $(CFLAGS) -o pipex

clean:
		@rm -rf $(BONUS_OBJS) $(OBJS)
		@make -C ./mandatory clean
		@make -C ./bonus clean

fclean:clean
		@make -C ./mandatory fclean
		@make -C ./bonus fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re