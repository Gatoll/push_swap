/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:38 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 07:06:00 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

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

static int	count_step_b(t_stack **stack_b, int step_b)
{
	int		len_b;
	
	len_b = stack_len(stack_b);
	if (step_b > (len_b / 2))
		step_b = (len_b - step_b) * -1;
	return (step_b);
}

void	get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a, int *step_b)
{
	int		tmp_step_a;
	int 	tmp_step_b;
	int		count;
	t_stack	*current;

	current = *stack_b;
	count = 0;
	*step_a = count_step_a(stack_a, current->value);
	*step_b = count;
	current = current->next;
	count++;
	while (current != NULL)
	{
		tmp_step_a = count_step_a(stack_a, current->value);
		tmp_step_b = count_step_b(stack_b, count);
		if (ft_union(tmp_step_a, tmp_step_b) < ft_union(*step_a, *step_b))
		{
			*step_a = tmp_step_a;
			*step_b = tmp_step_b;
		}
		count++;
		current = current->next;
	}
}
