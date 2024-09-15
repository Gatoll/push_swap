/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:28 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 08:35:12 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line_bonus.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int	arg_to_stack(int argc, char *argv[], t_stack **stack_a);
void	free_stack(t_stack **stack);
void				free_tmp(char **tmp);
char				**ft_split_multi(char const *s, char *c);
int	init_stack(int argc, char *argv[], t_stack **stack_a);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
int	count_step_a(t_stack **stack_a, int b_value);
void	get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a, int *step_b);
void	separate_stack(t_stack **stack_a, t_stack **stack_b, int len_a);
void	sort_over6(t_stack **stack_a, t_stack **stack_b, int len_a);
void				push_swap(t_stack **stack_a, t_stack **stack_b);
void				sort_3_a(t_stack **stack_a);
void	sort_4_a(t_stack **stack_a, t_stack **stack_b, int len_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int len_a);
void				put_error(void);
int					is_sorted(t_stack **stack);
int					stack_len(t_stack **stack);
int	serch_min(t_stack **stack, int *len_to_min);
int is_empty(t_stack **stack);

#endif