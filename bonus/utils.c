/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:32 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:23 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	int		count;
	t_stack	*current;

	min = (*stack)->value;
	current = (*stack)->next;
	count = 0;
	*len_to_min = count;
	while (current != NULL)
	{
		if (current->value < min)
		{
			min = current->value;
			*len_to_min = count;
		}
		current = current->next;
		count++;
	}
	return (min);
}

int	is_empty(t_stack **stack)
{
	if (*stack == NULL)
		return (TRUE);
	return (FALSE);
}
