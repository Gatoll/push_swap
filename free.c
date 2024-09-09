#include "push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack	*tmp;

    if (!stack)
		return ;
    while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_tmp(char **tmp)
{
    char **start;

    start = tmp;
	while (*tmp != NULL)
	{
		free(*tmp);
		tmp++;
	}
	free(start);
}
