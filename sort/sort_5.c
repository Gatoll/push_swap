#include "push_swap.h"

static int serch_med_5(t_stack **stack)
{
    int med;
    int count;
    t_stack *current;
    t_stack *current2;

    current = *stack;
    while (current != NULL)
    {
        count = 0;
        current2 = *stack;
        while (current2 != NULL)
        {
            if (current->value > current2->value)
                count++;
            current2 = current2->next;
        }
        if (count == 2)
        {
            med = current->value;
            return (med);
        }
        current = current->next;
    }
    return (FALSE);
}

void sort_5(t_stack **stack_a, t_stack **stack_b)
{
    int med;
    int len_a;
    int i;

    med = serch_med_5(stack_a);
    len_a = stack_len(stack_a);
    i = 0;
    while (i < len_a)
    {
        if ((*stack_a)->value < med)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    sort_3_a(stack_a);
    if ((*stack_b)->value < (*stack_b)->next->value)
        sb(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
