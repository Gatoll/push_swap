#include "push_swap.h"

void put_error(void)
{
    write(1, "Error\n", 6);
}

int init_stack(int argc, char *argv[], t_stack **stack_a)
{
    if (arg_to_stack(argc, argv, stack_a) == FALSE)
        return (FALSE);
    if (is_unique_node(stack_a) == FALSE)
    {
        free_stack(stack_a);
        return (FALSE);
    }
    if (is_sorted(stack_a) == TRUE)
    {
        free_stack(stack_a);
        return (FALSE);
    }
    return (TRUE);
}

#include <stdio.h>
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

#include <stdio.h>
int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (argc == 1)
        return (1);
    if (init_stack(argc, argv, &stack_a) == FALSE)
        return (1);

    put_stack(stack_a, stack_b);
    push_swap(&stack_a, &stack_b);
    put_stack(stack_a, stack_b);
    
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
