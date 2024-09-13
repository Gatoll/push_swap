# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:06:24 by kaokazak          #+#    #+#              #
#    Updated: 2024/09/14 03:15:08 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

DIR_LIBFT = libft

SRCS = init_stack/arg_to_stack.c \
	   init_stack/free.c \
	   init_stack/ft_split_multi.c \
	   init_stack/init_stack.c \
	   operate/push.c \
	   operate/reverse_rotate.c \
	   operate/rotate.c \
	   operate/swap.c \
	   sort/sort_over6/count_step_a.c \
	   sort/sort_over6/get_min_step.c \
	   sort/sort_over6/separate_stack.c \
	   sort/sort_over6/sort_over6.c \
	   sort/push_swap.c \
	   sort/sort_3.c \
	   sort/sort_4.c \
	   sort/sort_5.c \
	   main.c \
	   utils.c \
	   test.c

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
