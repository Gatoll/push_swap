#include "push_swap.h"

void sort_3(t_stack **stack_a)
{
    int first;
    int second;
    int third;
    
    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    if (first < second && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && third < first)
        rra(stack_a);
    else if (first > second && second < third && third > first)
        sa(stack_a);
    else if (first > second && second > third && third < first)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && third < first)
        ra(stack_a);
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

void sort_4to6(t_stack **stack_a, t_stack **stack_b)
{
    int min;

    while (stack_len(stack_a) > 3)
    {
        min = serch_min(stack_a);
        while ((*stack_a)->value != min)
            ra(stack_a);
        pb(stack_b, stack_a);
    }
    if (is_sorted(stack_a) == FALSE)
        sort_3(stack_a);
    while ((*stack_b) != NULL)
        pa(stack_a, stack_b);
}

// void set_min_max(t_stack **stack_a, int max, int min)
// {
//     if ((*stack_a)->value < (*stack_a)->next->value)
//     {
//         min = (*stack_a)->value;  
//         max = (*stack_a)->next->value;
//     }
//     else
//     {
//         min = (*stack_a)->next->value; 
//         max = (*stack_a)->value;
//     }
// }

void partition_stack(t_stack **stack_a, t_stack **stack_b, int pivot)
{
    if (*stack_a)
    {
        if ((*stack_a)->value < pivot)
            pb(stack_b, stack_a);
        else
            ra(stack_a);
    }
}

void quick_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
    int pivot;
    int len_a;
    int len_b;

    if (len <= 3)
    {
        if (!is_sorted(stack_a))
            sort_3(stack_a);
        return;
    }
    pivot = (*stack_a)->value;
    partition_stack(stack_a, stack_b, pivot);
    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);
    quick_sort(stack_a, stack_b, len_a);
    while (len_b > 0)
    {
        pa(stack_a, stack_b);
        len_b--;
    }
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int len;

    if (is_sorted(stack_a) == TRUE)
        return ;
    len = stack_len(stack_a);
    if (len == 2)
        sa(stack_a);
    if (len == 3)
        sort_3(stack_a);
    if (4 <= len && len <= 6)
        sort_4to6(stack_a, stack_b);
    else
        quick_sort(stack_a, stack_b, len);
}
