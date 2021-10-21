CC = gcc
NAME = pipex_bonus
flags = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_split.c   tools.c ft_putendl_fd.c ft_strchr.c  utils.c  ft_strncmp.c ft_strdup.c ft_strjoin.c ft_substr.c gnl_bonus.c multiple_pipes.c

all : $(NAME)
$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
	@echo "Rebuilding Library."
