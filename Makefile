# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 16:06:24 by kaokazak          #+#    #+#              #
#    Updated: 2024/09/16 07:10:20 by kaokazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

DIR_LIBFT = libft

SRCS = mandatory/init_stack/arg_to_stack.c \
		mandatory/init_stack/free.c \
		mandatory/init_stack/ft_split_multi.c \
		mandatory/init_stack/init_stack.c \
		mandatory/operate/push.c \
		mandatory/operate/reverse_rotate.c \
		mandatory/operate/rotate.c \
		mandatory/operate/swap.c \
		mandatory/sort/sort_over6/count_step_a.c \
		mandatory/sort/sort_over6/get_min_step.c \
		mandatory/sort/sort_over6/separate_stack.c \
		mandatory/sort/sort_over6/sort_over6.c \
		mandatory/sort/push_swap.c \
		mandatory/sort/sort_3.c \
		mandatory/sort/sort_4.c \
		mandatory/sort/sort_5.c \
		mandatory/main.c \
		mandatory/utils.c \
	   
BONUS = bonus/init_stack/arg_to_stack.c \
		bonus/init_stack/free.c \
		bonus/init_stack/ft_split_multi.c \
		bonus/init_stack/init_stack.c \
		bonus/operate/push.c \
		bonus/operate/reverse_rotate.c \
		bonus/operate/rotate.c \
		bonus/operate/swap.c \
		bonus/checker.c \
		bonus/sort/sort_over6/count_step_a.c \
		bonus/sort/sort_over6/get_min_step.c \
		bonus/sort/sort_over6/separate_stack.c \
		bonus/sort/sort_over6/sort_over6.c \
		bonus/sort/push_swap.c \
		bonus/sort/sort_3.c \
		bonus/sort/sort_4.c \
		bonus/sort/sort_5.c \
		bonus/checker.c \
		bonus/utils.c 
	   
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(DIR_LIBFT)/libft.a:
	make -C ./$(DIR_LIBFT)

$(NAME): $(DIR_LIBFT)/libft.a $(OBJS)
	$(CC) $(OBJS) -L./$(DIR_LIBFT)/ -lft -o $(NAME)
	
bonus: $(DIR_LIBFT)/libft.a $(BONUS_OBJS)
	$(CC) $(OBJS) -L./$(DIR_LIBFT)/ -lft -o checker
	
.c.o:
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
	make fclean -C ./$(DIR_LIBFT)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

.PHONY: clean fclean re
