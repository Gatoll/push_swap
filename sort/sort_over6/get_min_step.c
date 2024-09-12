/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:38 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/12 18:25:41 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int ft_union(int num1, int num2)
{
	return (ft_abs(num1) + ft_abs(num2));
}

static int count_upper_value(t_stack **stack_a, int b_value)
{
	t_stack	*current;
	int step;
	
	current = *stack_a;
	step = 0;
	while (current->next != NULL && current->value < b_value && current->value < current->next->value)
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

static int count_lower_value(t_stack **stack_a, int b_value)
{
	t_stack	*current;
	int step;
	
	current = *stack_a;
	step = 0;
	
	while (current->next != NULL && b_value < current->value && current->value < current->next->value)
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

static int	count_step_a(t_stack **stack_a, int b_value)
{
	int		len_a;
	int		step;
	t_stack	*current;

	step = 0;
	current = *stack_a;

	if (current->value < b_value)
		step = count_upper_value(stack_a, b_value);
	else
		step = count_lower_value(stack_a, b_value);
	len_a = stack_len(stack_a);
	if (step > (len_a / 2))
		step = (len_a - step) * -1;
	return (step);
}

void	get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a,
        int *step_b)
{
	int		tmp_step_a;
	//int		tmp_step_b;
	int		count;
	t_stack	*current;

	current = *stack_b;
	count = 0;
	*step_a = count_step_a(stack_a, current->value);
	*step_b = count;//count_step_b(stack_b, current->value);
	//printf("value = %d : first_step_a = %d, first_step_b = %d\n", current->value, *step_a, *step_b);
	current = current->next;
	count++;
	while (current != NULL)
	{
		tmp_step_a = count_step_a(stack_a, current->value);
		//tmp_step_b = count_step_b(stack_b, count);
		//printf("tmp_step_a = %d, tmp_step_b = %d\n", tmp_step_a, count);
		if (ft_union(tmp_step_a, count) < ft_union(*step_a, *step_b))
		{
			*step_a = tmp_step_a;
			*step_b = count;
		}
		count++;
		current = current->next;
	}
}
