#include "push_swap.h"

static void swap(t_stack **stack)
{
    int tmp;
    
    if ((*stack) == NULL || (*stack)->next == NULL)
        return ;
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}

void sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}

