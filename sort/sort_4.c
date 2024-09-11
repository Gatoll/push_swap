/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:06 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/11 16:07:39 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_a(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	len_to_min;
	int	len_a;

	min = serch_min(stack_a, &len_to_min);
	len_a = stack_len(stack_a);
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
	pb(stack_a, stack_b);
	sort_3_a(stack_a);
	pa(stack_a, stack_b);
}
