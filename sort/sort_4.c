#include "push_swap.h"

void sort_4_a(t_stack **stack_a, t_stack **stack_b)
{
    int min;

    min = serch_min(stack_a);
    while ((*stack_a)->value != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    sort_3_a(stack_a);
    pa(stack_a, stack_b);
}
