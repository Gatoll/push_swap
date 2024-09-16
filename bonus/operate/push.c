/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:24 by kaokazak          #+#    #+#             */
/*   Updated: 2024/09/16 12:30:46 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if ((*src) == NULL)
		return ;
	tmp = *src;
	(*src) = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	if (*dest != NULL)
	{
		tmp->next = (*dest);
		(*dest)->prev = tmp;
	}
	else
		tmp->next = NULL;
	(*dest) = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}
