/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:32 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/12 01:44:06 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(void)
{
	write(1, "Error\n", 6);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
	{
		if ((current->value) > (current->next->value))
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

int	stack_len(t_stack **stack)
{
	int		len;
	t_stack	*current;

	len = 0;
	if (!stack)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

int	serch_min(t_stack **stack, int *len_to_min)
{
	int		min;
	t_stack	*current;

	min = (*stack)->value;
	current = (*stack)->next;
	len_to_min = 0;
	while (current != NULL)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
		len_to_min++;
	}
	return (min);
}
