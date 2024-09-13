/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:35 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/13 21:36:16 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pivot(t_stack **stack_a, int len_a, int *pivot)
{
	int		count;
	t_stack	*current;
	t_stack	*compare;

	current = *stack_a;
	while (current != NULL)
	{
		count = 0;
		compare = *stack_a;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				count++;
			compare = compare->next;
		}
		if (count == (len_a / 3 - 1))
			pivot[0] = current->value;
		else if (count == ((len_a / 3) * 2 + 1))
			pivot[1] = current->value;
		current = current->next;
	}
}

void	separate_stack(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	pivot[2];

	get_pivot(stack_a, len_a, pivot);
	//printf("pivot[0] = %d, pivot[1] = %d\n", pivot[0], pivot[1]);
	while (len_a-- > 0)
	{
		if ((*stack_a)->value <= pivot[0])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (pivot[0] < (*stack_a)->value && (*stack_a)->value < pivot[1])
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	len_a = stack_len(stack_a);
	while (len_a-- > 3)
		pb(stack_a, stack_b);
}
