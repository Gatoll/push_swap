/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:39:53 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 11:40:08 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mandatory/push_swap.h"
#include <stdio.h>

void	put_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	current = stack_a;
	printf("stack_a:");
	while (current != NULL)
	{
		printf("%d, ", current->value);
		current = current->next;
	}
	printf("\n");
	current = stack_b;
	printf("stack_b:");
	while (current != NULL)
	{
		printf("%d, ", current->value);
		current = current->next;
	}
	printf("\n");
}
