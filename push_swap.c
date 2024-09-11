#include "push_swap.h"

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

int count_step_a(t_stack **stack_a, int b_value)
{
    int len_a;
    int step_a;
    t_stack *current;

    len_a = stack_len(stack_a);
    step_a = 0;
    current = *stack_a;
    while (current != NULL && current->value < b_value)
    {
        step_a++;
        current = current->next;
    }
    if (step_a > (len_a / 2))
        step_a = (len_a - step_a) * -1;
    return (step_a);
}

int count_step_b(t_stack **stack_b, int tmp_step_b)
{
    int len_b;

    len_b = stack_len(stack_b);
    if (tmp_step_b > (len_b / 2))
        tmp_step_b = (len_b - tmp_step_b) * -1;
    return (tmp_step_b);
}

// int union_step(int step_a, int step_b)
// {
//     return (ft_abs(step_a)+ft_abs(step_b));
// }

void get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a, int *step_b)
{
    int tmp_step_a;
    int tmp_step_b;
    int count;
    t_stack *current;

    current = *stack_b;
    count = 0;
    while (current != NULL)
    {
        tmp_step_a = count_step_a(stack_a, current->value);
        tmp_step_b = count_step_b(stack_b, count);
        if (ft_abs(tmp_step_a) + ft_abs(tmp_step_b) < ft_abs(*step_a) + ft_abs(*step_b))
        {
            *step_a = tmp_step_a;
            *step_b = tmp_step_b;
        }
        count++;
        current = current->next;
    }
}

void do_rotate_a(t_stack **stack_a, int step_a)
{
    if (step_a > 0)
    {
        while (step_a > 0)
        {
            ra(stack_a);
            step_a--;
        }
    }
    else
    {
        while (step_a < 0)
        {
            rra(stack_a);
            step_a++;
        }
    }
}

void do_rotate_b(t_stack **stack_b, int step_b)
{
    if (step_b > 0)
    {
        while (step_b > 0)
        {
            rb(stack_b);
            step_b--;
        }
    }
    else
    {
        while (step_b < 0)
        {
            rrb(stack_b);
            step_b++;
        }
    }
}

void sort6_to(t_stack **stack_a, t_stack **stack_b)
{
    int step_a;
    int step_b;
    separate_stack(stack_a, stack_b);
    push_swap(stack_a, stack_b); // aのソートできた。次Bをstep数が少ない順番にpush .
    while ((*stack_b) != NULL)
    {
        get_min_step(stack_a, stack_b, &step_a, &step_b);
        do_rotate_a(stack_a, step_a);
        do_rotate_b(stack_b, step_b);
        pa(stack_a, stack_b);
    }
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int len_a;

    len_a = stack_len(stack_a);
    if (len_a == 2)
        sa(stack_a);
    else if (len_a == 3)
        sort_3_a(stack_a);
    else if (len_a == 4)
        sort_4_a(stack_a, stack_b);
    else if (len_a == 5)
        sort_5(stack_a, stack_b);
    else
        sort6_to(stack_a, stack_b);
}
