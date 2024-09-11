/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:38 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/12 02:02:13 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	count_step_b(t_stack **stack_b, int tmp_step_b)
{
	int	len_b;

	len_b = stack_len(stack_b);
	if (tmp_step_b > (len_b / 2))
		tmp_step_b = (len_b - tmp_step_b) * -1;
	return (tmp_step_b);
}

static int	count_step_a(t_stack **stack_a, int b_value)
{
	int		len_a;
	int		step_a;
	t_stack	*current;

	len_a = stack_len(stack_a);
	step_a = 0;
	current = *stack_a;
	while (current != NULL && current->value < b_value)
	{
		step_a++;
		current = current->next;
	}
	if (step_a > (len_a / 2))
		step_a = (len_a - step_a) * -1;
	return (step_a);
}

void	get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a,
        int *step_b)
{
	int		tmp_step_a;
	int		tmp_step_b;
	int		count;
	t_stack	*current;

	current = *stack_b;
	count = 0;
	while (current != NULL)
	{
		tmp_step_a = count_step_a(stack_a, current->value);
		tmp_step_b = count_step_b(stack_b, count);
		if (current->next == NULL)
		{
			*step_a = tmp_step_a;
			*step_b = tmp_step_b;
			return ;
		}
		if (ft_abs(tmp_step_a) + ft_abs(tmp_step_b) < ft_abs(*step_a)
			+ ft_abs(*step_b))
		{
			*step_a = tmp_step_a;
			*step_b = tmp_step_b;
		}
		count++;
		current = current->next;
	}
}
