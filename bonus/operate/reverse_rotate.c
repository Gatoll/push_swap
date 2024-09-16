/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:27 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 12:30:53 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_start;
	t_stack	*current;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next)
		current = current->next;
	new_start = current;
	new_start->prev->next = NULL;
	new_start->prev = NULL;
	new_start->next = *stack;
	(*stack)->prev = new_start;
	*stack = new_start;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
