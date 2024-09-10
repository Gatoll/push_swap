#include "push_swap.h"

void sort_3_a(t_stack **stack_a)
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

// void sort_3_b(t_stack **stack_b)
// {
//     int first;
//     int second;
//     int third;
    
//     first = (*stack_b)->value;
//     second = (*stack_b)->next->value;
//     third = (*stack_b)->next->next->value;
//     if (first < second && first < third)
//     {
//         sb(stack_b);
//         rb(stack_b);
//     }
//     else if (first < second && second > third && third < first)
//         rrb(stack_b);
//     else if (first > second && second < third && third > first)
//         sb(stack_b);
//     else if (first > second && second > third && third < first)
//     {
//         sb(stack_b);
//         rrb(stack_b);
//     }
//     else if (first > second && second < third && third < first)
//         rb(stack_b);
// }

#include <stdio.h>
int serch_med_5(t_stack **stack)
{
    int med;
    int count;
    t_stack *current;
    t_stack *current2;

    current = *stack;
    while (current != NULL)
    {
        count = 0;
        current2 = current->next;
        while (current2 != NULL)
        {
            if (current->value > current2->value)
                count++;
            current2 = current2->next;
        }
        printf("%d\n", count);
        if (count == 2)
        {
            med = current->value;
            return (med);
        }
        current = current->next;
    }
    return (FALSE);
}

void sort_4_a(t_stack **stack_a, t_stack **stack_b)
{
    int min;
    t_stack *current;

    min = serch_min(stack_a);
    current = (*stack_a);
    while (current->value != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    sort_3_a(stack_a);
    pa(stack_a, stack_b);
}

void sort_5(t_stack **stack_a, t_stack **stack_b)
{
    int med;
    t_stack *current;

    current = (*stack_a);
    med = serch_med_5(stack_a);
    while (current != NULL)
    {
        if (current->value < med)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        current = current->next;
    }
    sort_3_a(stack_a);
    if ((*stack_b)->value < (*stack_b)->next->value)
        sb(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
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
            sort_3_a(stack_a);
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
    int len_a;

    len_a = stack_len(stack_a);
    if (len_a == 2)
        sa(stack_a);
    if (len_a == 3)
        sort_3_a(stack_a);
    else
        quick_sort(stack_a, stack_b, len_a);
}

// void pibot(t_stack **stack)
// {
//     int i;
//     int j;
//     int len_a;
//     int count;

//     i = 0;
//     j = 0;
//     len_a = stack_len(stack);
//     count = 0;

//     while (i < len_a)
//     {
//         while (j < )
//         {
//             if ()
//                 count++;
//             j++;
//         }
//         i++;
//     }
// }
