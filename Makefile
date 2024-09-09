NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

DIR_LIBFT = libft

SRCS = operate/push.c \
	   operate/reverse_rotate.c \
	   operate/rotate.c \
	   operate/swap.c \
	   check.c \
	   free.c \
	   main.c \
	   create_stack.c \
	   push_swap.c \
	   ft_split_multi.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(DIR_LIBFT)/libft.a:
	make -C ./$(DIR_LIBFT)

$(NAME): $(DIR_LIBFT)/libft.a $(OBJS)
	$(CC) $(OBJS) -L./$(DIR_LIBFT)/ -lft -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
	make fclean -C ./$(DIR_LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
