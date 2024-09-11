#include "push_swap.h"

void sort_3_a(t_stack **stack_a)
{
    int first;
    int second;
    int third;
    
    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    if(first < second && second < third)
        return ;
    else if (first < second && second > third && third > first)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first > second && second < third && third > first)
        sa(stack_a);
    else if (first < second && second > third && third < first)
        rra(stack_a);
    else if (first > second && second < third && third < first)
        ra(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
}
