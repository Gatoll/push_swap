#include "push_swap.h"

static void push(t_stack **dest, t_stack **src)
{
    t_stack *tmp;
    
    if ((*src) == NULL)
        return ;

    tmp = *src;
    (*src) = (*src)->next;
    if (*src != NULL)
        (*src)->prev = NULL;
    
    if (*dest != NULL)
    {
        tmp->next = (*dest);
        (*dest)->prev = tmp;
    }
    else
        tmp->next = NULL;
    (*dest) = tmp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
   push(stack_b, stack_a);
   write(1, "pb\n", 3);
}
