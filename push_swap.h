/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:28 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/14 03:16:20 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// init_stack/
// arg_to_stack
int	arg_to_stack(int argc, char *argv[], t_stack **stack_a);
// free
void				free_stack(t_stack **stack);
void				free_tmp(char **tmp);
// ft_split_multi
char				**ft_split_multi(char const *s, char *c);
// init_stack
int	init_stack(int argc, char *argv[], t_stack **stack_a);


// oprate/
// push
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

// swap
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

// rotate
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);


// sort/
// sort_over6/
// count_step_a
int	count_step_a(t_stack **stack_a, int b_value);
// get_min_step
void	get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a, int *step_b);
// separate_stack
void	separate_stack(t_stack **stack_a, t_stack **stack_b, int len_a);
// sort_over6
void	sort_over6(t_stack **stack_a, t_stack **stack_b, int len_a);

// push_swap
void				push_swap(t_stack **stack_a, t_stack **stack_b);
// sort_3
void				sort_3_a(t_stack **stack_a);
// sort_4
void	sort_4_a(t_stack **stack_a, t_stack **stack_b, int len_a);
// sort_5
void	sort_5(t_stack **stack_a, t_stack **stack_b, int len_a);


// utils
void				put_error(void);
int					is_sorted(t_stack **stack);
int					stack_len(t_stack **stack);
int	serch_min(t_stack **stack, int *len_to_min);


# include <stdio.h>
void				put_stack(t_stack *stack_a, t_stack *stack_b);

#endif