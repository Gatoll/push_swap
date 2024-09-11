/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:00 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/11 16:07:31 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(stack_a);
	if (len_a == 2)
		sa(stack_a);
	else if (len_a == 3)
		sort_3_a(stack_a);
	else if (len_a == 4)
		sort_4_a(stack_a, stack_b);
	else if (len_a == 5)
		sort_5(stack_a, stack_b);
	else
		sort_over6(stack_a, stack_b);
}
