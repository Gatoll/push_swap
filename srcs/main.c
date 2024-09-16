/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:18 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 23:15:53 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// __attribute__((destructor))
// static void destructor() { 
//     system("leaks -q push_swap");
// }

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (init_stack(argc, argv, &stack_a) == FALSE)
		return (1);
	if (is_sorted(&stack_a) == TRUE)
	{
		free_stack(&stack_a);
		return (FALSE);
	}
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
