/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:30 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 12:30:56 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*new_start;
	t_stack	*new_end;
	t_stack	*current;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	new_end = *stack;
	new_start = (*stack)->next;
	new_start->prev = NULL;
	current = new_start;
	while (current->next)
		current = current->next;
	current->next = new_end;
	new_end->prev = current;
	new_end->next = NULL;
	*stack = new_start;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
