/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:34:43 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 23:15:01 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	count_upper_value(t_stack **stack_a, int b_value)
{
	t_stack	*current;
	int		step;

	current = *stack_a;
	step = 0;
	while (current->next != NULL && current->value < b_value
		&& current->value < current->next->value)
	{
		step++;
		current = current->next;
	}
	if (current->value < b_value)
	{
		step++;
		current = current->next;
	}
	return (step);
}

static int	count_lower_value(t_stack **stack_a, int b_value)
{
	t_stack	*current;
	int		step;

	current = *stack_a;
	step = 0;
	while (current->next != NULL && b_value < current->value
		&& current->value < current->next->value)
	{
		step++;
		current = current->next;
	}
	step++;
	current = current->next;
	if (current == NULL)
		step = 0;
	while (current != NULL && current->value < b_value)
	{
		step++;
		current = current->next;
	}
	return (step);
}

int	count_step_a(t_stack **stack_a, int b_value)
{
	int		len_a;
	int		step_a;
	t_stack	*current;

	step_a = 0;
	current = *stack_a;
	if (current->value < b_value)
		step_a = count_upper_value(stack_a, b_value);
	else
		step_a = count_lower_value(stack_a, b_value);
	len_a = stack_len(stack_a);
	if (step_a > (len_a / 2))
		step_a = (len_a - step_a) * -1;
	return (step_a);
}
