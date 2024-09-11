#include "push_swap.h"

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

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

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

    //put_stack(stack_a, stack_b);
    push_swap(&stack_a, &stack_b);
    //put_stack(stack_a, stack_b);
    
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
