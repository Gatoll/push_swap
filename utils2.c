#include "push_swap.h"

int ft_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

void put_error(void)
{
    write(1, "Error\n", 6);
}

int serch_min(t_stack **stack)
{
    int min;
    t_stack *current;

    min = (*stack)->value;
    current = (*stack)->next;
    while (current != NULL)
    {
        if (min > current->value)
            min = current->value;
        current = current->next;
    }
    return (min);
}

void get_pivot(t_stack **stack, int *pivot)
{
    int count;
    int len;
    t_stack *current;
    t_stack *current2;

    current = *stack;
    len = stack_len(stack);
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
        if (count == (len / 3))
            pivot[0] = current->value;
        else if (count == (len / 3 * 2))
            pivot[1] = current->value;
        current = current->next;
    }
}

void separate_stack(t_stack **stack_a, t_stack **stack_b)
{
    int pivot[2];
    int len_a;
    int i;

    get_pivot(stack_a, pivot);
    len_a = stack_len(stack_a);
    i = 0;
    while (i < len_a)
    {
        if ((*stack_a)->value <= pivot[0])
        {
            pb(stack_a, stack_b);
            rb(stack_b);
        }
        else if (pivot[0] < (*stack_a)->value && (*stack_a)->value < pivot[1])
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    len_a = stack_len(stack_a);
    while (len_a-- > 5)
        pb(stack_a, stack_b);
}
