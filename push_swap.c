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
    else if (first < second && first < third)
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

// void sort_4_a(t_stack **stack_a, t_stack **stack_b)
// {
//     int min;
//     int len_a;
//     int i;

//     min = serch_min(stack_a);
//     len_a = stack_len(stack_a);
//     i = 0;
//     while (i < len_a)
//     {
//         if ((*stack_a)->value == min)
//         {
//             pa(stack_a, stack_b);
//             return ;
//         }
//         else
//             ra(stack_a);
//         i++;
//     }
//     pb(stack_a, stack_b);
//     sort_3_a(stack_a);
//     pa(stack_a, stack_b);
// }

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

// void quick_sort(t_stack **stack_a, t_stack **stack_b, int len)
// {
//     int pivot;
//     int len_a;
//     int len_b;

//     if (len <= 3)
//     {
//         if (!is_sorted(stack_a))
//             sort_3_a(stack_a);
//         return;
//     }
//     pivot = (*stack_a)->value;
//     partition_stack(stack_a, stack_b, pivot);
//     len_a = stack_len(stack_a);
//     len_b = stack_len(stack_b);
//     quick_sort(stack_a, stack_b, len_a);
//     while (len_b > 0)
//     {
//         pa(stack_a, stack_b);
//         len_b--;
//     }
// }
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

void partition_stack(t_stack **stack_a, t_stack **stack_b)
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

int count_step_a(t_stack **stack_a, int value)
{
    int step_a;
    int *current;
    int len_a;

    current = (*stack_a);
    step_a = 0;
    len_a = stack_len(stack_a);
    while (current != NULL && (*stack_a)->next->value < value)
    {
        step_a++;
        current = current->next;
    }
    if (step_a > (len_a / 2))
            step_a = (len_a - step_a) * -1;
    return (step_a);
}

int ft_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

int count_stap(t_stack **stack_a, t_stack *stack_b)
{
    int count_a;
    int count_b;
    int tmp_count_a;
    int tmp_count_b;
    t_stack *current_b;
    int len_b;

    current_b = (*stack_b);
    len_b = len_stack(stack_b);
    tmp_count_b = 0;
    while (current_b != NULL)
    {
        tmp_count_b++;
        if (tmp_count_b > (len_b / 2))
            tmp_count_b = (len_b - tmp_count_b) * -1;
        tmp_count_a = count_step_a(stack_a, current_b->value);
        if (ft_abs(tmp_count_a)+ft_abs(tmp_count_b) < (ft_abs(count_a)+ft_abs(count_b)))
        {
            count_a = tmp_count_a;
            count_b = tmp_count_b;
        }
        current_b = current_b->next;
    }
}

void sort6_to(t_stack **stack_a, t_stack **stack_b)
{
    //int len_a;

    partition_stack(stack_a, stack_b);
    //len_a = stack_len(stack_a);
    push_swap(stack_a, stack_b);
    while ((*stack_b) != NULL)
    {
        
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
