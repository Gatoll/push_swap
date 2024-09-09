#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *new_start;
    t_stack *new_end;
    t_stack *current;

    if ((*stack) == NULL || (*stack)->next == NULL)
        return ;
    
    new_end = *stack;
    new_start = (*stack)->next;
    new_start->prev = NULL;

    current = new_start;
    while (current->next)
		current = current->next;

    current->next = new_end;
    new_end->prev = current;
    new_end->next = NULL;

    *stack = new_start;
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}
