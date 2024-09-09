#include "push_swap.h"

// make_stack->add_stack
#include <stdio.h>
int main(void)
{
    t_stack *stack_a = NULL;
    int i = 0;
    while (i < 5)
    {
        add_stack(&stack_a, i);
        i++;
    }
    t_stack *current;
    current = stack_a;
    while (current != NULL)
    {
        printf("%d, ", current->value);
        current = current->next;
    }
    printf("\n");
    return 0;
}

// split2
#include <stdio.h>
int main(int argc, char *argv[])
{
    (void)argc;
    char **result = ft_split2(argv[1], ", ");

    if (result == NULL) {
        printf("ft_split: メモリ割り当てエラー\n");
        return 1;
    }

    int i = 0;
    while (result[i] != NULL) {
        printf("%s\n", result[i]);
        i++;
    }

    // メモリ解放
    ft_free2(result, i);

    return 0;
}
