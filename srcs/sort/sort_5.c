/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:09 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 23:15:38 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	serch_med_5(t_stack **stack)
{
	int		count;
	t_stack	*current;
	t_stack	*compare;

	current = *stack;
	while (current != NULL)
	{
		count = 0;
		compare = *stack;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				count++;
			compare = compare->next;
		}
		if (count == 2)
			return (current->value);
		current = current->next;
	}
	return (FALSE);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	med;

	med = serch_med_5(stack_a);
	while (len_a-- > 0)
	{
		if ((*stack_a)->value < med)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3_a(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
