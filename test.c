#include <stdio.h>
#include "push_swap.h"

void put_stack(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current;

    current = stack_a;
    printf("stack_a:");
    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    }
    printf("\n");
    
    current = stack_b;
    printf("stack_b:");
    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    } 
    printf("\n");
}
