#include "push_swap_bonus.h"

static int ft_strcmp(const char *s1, const char *s2)
{
    size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int line_to_operate(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(line, "pa\n") == 0)
        pa(stack_a, stack_b);
    else if (ft_strcmp(line, "pb\n") == 0)
        pb(stack_a, stack_b);    
    else if (ft_strcmp(line, "rra\n") == 0)
        rra(stack_a);
    else if (ft_strcmp(line, "rrb\n") == 0)
        rrb(stack_b);
    else if (ft_strcmp(line, "rrr\n") == 0)
        rrr(stack_a, stack_b);
    else if (ft_strcmp(line, "ra\n") == 0)
        ra(stack_a);
    else if (ft_strcmp(line, "rb\n") == 0)
        rb(stack_b);
    else if (ft_strcmp(line, "rr\n") == 0)
        rr(stack_a, stack_b);
    else if (ft_strcmp(line, "sa\n") == 0)
        sa(stack_a);
    else if (ft_strcmp(line, "sb\n") == 0)
        sb(stack_b);
    else if (ft_strcmp(line, "ss\n") == 0)
        ss(stack_a, stack_b);
    else
        return (FALSE);
    return (TRUE);
}

static int read_line(t_stack **stack_a, t_stack **stack_b)
{
    char *line;

    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        if (line_to_operate(line, stack_a, stack_b) == FALSE)
        {
            put_error();
            free(line);
            return (FALSE);
        }
        free(line);
    }
    return (TRUE);
}

static void judge(t_stack **stack_a, t_stack **stack_b)
{
    if (is_sorted(stack_a) == TRUE && is_empty(stack_b) == TRUE)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (init_stack(argc, argv, &stack_a) == FALSE)
		return (1);
    if (read_line(&stack_a, &stack_b) == FALSE)
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    judge(&stack_a, &stack_b);
	free_stack(&stack_a);
    free_stack(&stack_b);
	return (0);
}
