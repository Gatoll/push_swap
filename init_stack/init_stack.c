/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:35 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/12 01:55:40 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_unique_node(t_stack **stack_a)
{
	t_stack	*start;
	t_stack	*current;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (FALSE);
	start = *stack_a;
	while (start != NULL)
	{
		current = start->next;
		while (current != NULL)
		{
			if (current->value == start->value)
			{
				put_error();
				return (FALSE);
			}
			current = current->next;
		}
		start = start->next;
	}
	return (TRUE);
}

int	init_stack(int argc, char *argv[], t_stack **stack_a)
{
	if (arg_to_stack(argc, argv, stack_a) == FALSE)
		return (FALSE);
	if (is_unique_node(stack_a) == FALSE)
	{
		free_stack(stack_a);
		return (FALSE);
	}
	if (is_sorted(stack_a) == TRUE)
	{
		free_stack(stack_a);
		return (FALSE);
	}
	return (TRUE);
}
