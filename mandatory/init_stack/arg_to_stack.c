#include "../push_swap.h"

static int	add_stack(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*current;

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

static int	is_intover(int sign, long res, long num)
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

static int	check_atoi(char *str, long *res)
{
	int	sign;

	sign = 1;
	*res = 0;
	if (!str || *str == '\0' || (*str != '+' && *str != '-'
			&& !ft_isdigit(*str)))
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

static int	tmp_to_stack(t_stack **stack_a, char **tmp)
{
	long	num;

	while (*tmp != NULL)
	{
		if (check_atoi(*tmp, &num) == FALSE)
		{
			put_error();
			return (FALSE);
		}
		if (add_stack(stack_a, num) == FALSE)
			return (FALSE);
		tmp++;
	}
	return (TRUE);
}

int	arg_to_stack(int argc, char *argv[], t_stack **stack_a)
{
	int		i;
	char	**tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_split_multi(argv[i], " ,");
		if (!tmp || *tmp == NULL)
		{
			put_error();
			free_tmp(tmp);
			return (FALSE);
		}
		if (tmp_to_stack(stack_a, tmp) == FALSE)
		{
			free_tmp(tmp);
			return (FALSE);
		}
		free_tmp(tmp);
		i++;
	}
	return (TRUE);
}
