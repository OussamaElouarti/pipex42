CC = gcc
NAME = pipex_mandatory
FLAGS = -Wall -Wextra -Werror
SRCS = ft_split.c   tools.c ft_putendl_fd.c ft_strchr.c utils.c  ft_strncmp.c ft_strdup.c ft_strjoin.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: 
	@rm -rf $(NAME) 

re: fclean all
	@echo "Rebuilding Library."

