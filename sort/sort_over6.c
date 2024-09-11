#include "push_swap.h"

void sort_over6(t_stack **stack_a, t_stack **stack_b)
{
    int step_a;
    int step_b;
    separate_stack(stack_a, stack_b);
    push_swap(stack_a, stack_b);
    while ((*stack_b) != NULL)
    {
        get_min_step(stack_a, stack_b, &step_a, &step_b);
        do_rotate_a(stack_a, step_a);
        do_rotate_b(stack_b, step_b);
        pa(stack_a, stack_b);
    }
}
