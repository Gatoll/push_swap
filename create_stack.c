#include "push_swap.h"

int add_stack(t_stack **stack_a, int num)
{
    t_stack *new_node;
    t_stack *current;

    new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (FALSE);

    new_node->value = num;
    new_node->next = NULL;
    if (*stack_a == NULL)
    {
        new_node->prev = NULL;
        *stack_a = new_node;
    }
    else
    {
        current = *stack_a;
        while (current->next)
            current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
    return (TRUE);
}

int tmp_to_stack(t_stack **stack_a, char **tmp)
{
    long num;

    while (*tmp != NULL)
    {
        if (check_atoi(*tmp, &num) == FALSE)
            return (FALSE);
        if (add_stack(stack_a, num) == FALSE)
            return (FALSE);
        tmp++;
    }
    return (TRUE);
}

int arg_to_stack(int argc, char *argv[], t_stack **stack_a)
{
    int i;
    char **tmp;
    
    i = 1;
    while (i < argc)
    {
        tmp = ft_split_multi(argv[i], " ,");
        if (!tmp)
            return (FALSE);
        if (tmp_to_stack(stack_a, tmp) == FALSE)
        {
            free_tmp(tmp);
            free_stack(stack_a);
            return (FALSE);
        }
        free_tmp(tmp);
        i++;
    }
    return (TRUE);
}
