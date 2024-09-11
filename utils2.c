#include "push_swap.h"

int ft_abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

void put_error(void)
{
    write(1, "Error\n", 6);
}
