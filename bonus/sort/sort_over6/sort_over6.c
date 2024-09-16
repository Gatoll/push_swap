/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:11 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:01 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

static void	end_rotate(t_stack **stack_a, int len_a)
{
	int	len_to_min;
	int	min;

	min = serch_min(stack_a, &len_to_min);
	if (len_to_min < (len_a / 2))
	{
		while ((*stack_a)->value != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a);
	}
}

static void	do_rotate_b(t_stack **stack_b, int step_b)
{
	if (step_b > 0)
	{
		while (step_b-- > 0)
			rb(stack_b);
	}
	else
	{
		while (step_b++ < 0)
			rrb(stack_b);
	}
}

static void	do_rotate_a(t_stack **stack_a, int step_a)
{
	if (step_a > 0)
	{
		while (step_a-- > 0)
			ra(stack_a);
	}
	else
	{
		while (step_a++ < 0)
			rra(stack_a);
	}
}

static void	do_rotate(t_stack **stack_a, t_stack **stack_b, int step_a,
		int step_b)
{
	if (step_a > 0 && step_b > 0)
	{
		while (step_a > 0 && step_b > 0)
		{
			rr(stack_a, stack_b);
			step_a--;
			step_b--;
		}
	}
	else if (step_a < 0 && step_b < 0)
	{
		while (step_a > 0 && step_b > 0)
		{
			rrr(stack_a, stack_b);
			step_a++;
			step_b++;
		}
	}
	do_rotate_a(stack_a, step_a);
	do_rotate_b(stack_b, step_b);
}

void	sort_over6(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	step_a;
	int	step_b;

	separate_stack(stack_a, stack_b, len_a);
	push_swap(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		get_min_step(stack_a, stack_b, &step_a, &step_b);
		do_rotate(stack_a, stack_b, step_a, step_b);
		pa(stack_a, stack_b);
	}
	end_rotate(stack_a, len_a);
}
