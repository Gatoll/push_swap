#include "push_swap.h"

int is_sorted(t_stack **stack)
{
    t_stack *current;
    
    current = *stack;
    while (current->next)
    {
        if ((current->value) > (current->next->value))
            return (FALSE);
        current = current->next;
    }
    return (TRUE);
}

int is_unique_node(t_stack **stack_a)
{
    t_stack *start;
    t_stack *current;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return (FALSE);
        
    start = *stack_a;
    while (start != NULL)
    {
        current = start->next;
        while (current != NULL)
        {
            if (current->value == start->value)
            {
                put_error();
                return (FALSE);
            }
                
            current = current->next;
        }
        start = start->next;
    }
    return (TRUE);
}

int stack_len(t_stack **stack)
{
    int len;
    t_stack *current;

    len = 0;
	if (!stack)
		return (0);
    current = *stack;
	while (current != NULL)
    {
		current = current->next;
        len++;
    }
	return (len);
}

int	is_intover(int sign, long res, long num)
{
	if (res > (long)INT_MAX / 10)
		return (TRUE);
	if (res == (long)INT_MAX / 10)
	{
		if (sign == 1 && num > (long)INT_MAX % 10)
			return (TRUE);
		if (sign == -1 && num > ((long)INT_MIN % 10) * -1)
			return (TRUE);
	}
	return (FALSE);
}

int check_atoi(char *str, long *res)
{
    int sign;

    sign = 1;
	*res = 0;

    if (!str || *str == '\0' || (*str != '+' && *str != '-' && !ft_isdigit(*str)))
        return (FALSE);
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str != '\0')
    {
        if (!ft_isdigit(*str) || is_intover(sign, *res, (*str - '0')))
            return (FALSE);
        *res = *res * 10 + (*str - '0');
        str++;
    }
    *res *= sign;
    return (TRUE);
}
