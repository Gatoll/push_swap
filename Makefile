# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:06:24 by kaokazak          #+#    #+#              #
#    Updated: 2024/09/16 12:35:10 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

DIR_LIBFT = libft
NAME_CHECKER = checker

SRCS = init_stack/arg_to_stack.c \
		init_stack/free.c \
		init_stack/init_stack.c \
		sort/sort_over6/count_step_a.c \
		sort/sort_over6/get_min_step.c \
		sort/sort_over6/separate_stack.c \
		sort/sort_over6/sort_over6.c \
		sort/push_swap.c \
		sort/sort_3.c \
		sort/sort_4.c \
		sort/sort_5.c \
		utils.c \
		operate/push.c \
		operate/reverse_rotate.c \
		operate/rotate.c \
		operate/swap.c \
		main.c
	   
BONUS = init_stack/arg_to_stack.c \
		init_stack/free.c \
		init_stack/init_stack.c \
		sort/sort_over6/count_step_a.c \
		sort/sort_over6/get_min_step.c \
		sort/sort_over6/separate_stack.c \
		sort/sort_over6/sort_over6.c \
		sort/push_swap.c \
		sort/sort_3.c \
		sort/sort_4.c \
		sort/sort_5.c \
		utils.c \
		bonus/operate/push.c \
		bonus/operate/reverse_rotate.c \
		bonus/operate/rotate.c \
		bonus/operate/swap.c \
		bonus/checker.c
	   
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(DIR_LIBFT)/libft.a:
	make -C ./$(DIR_LIBFT)

$(NAME): $(DIR_LIBFT)/libft.a $(OBJS)
	$(CC) $(OBJS) -L./$(DIR_LIBFT)/ -lft -o $(NAME)
	
bonus: $(DIR_LIBFT)/libft.a $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -L./$(DIR_LIBFT)/ -lft -o $(NAME_CHECKER)
	
.c.o:
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
	make fclean -C ./$(DIR_LIBFT)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: clean fclean re
