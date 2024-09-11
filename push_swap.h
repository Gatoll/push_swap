# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/include/libft.h"

typedef struct s_stack
{
	int             value;
    struct s_stack   *prev;
	struct s_stack	*next;
}					t_stack;

// oprate/
// push
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

// swap
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);

// rotate
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);


// sort
// sort_3
void sort_3_a(t_stack **stack_a);

// sort_4
void sort_4_a(t_stack **stack_a, t_stack **stack_b);

// sort_5
void sort_5(t_stack **stack_a, t_stack **stack_b);

// create_stack
int add_stack(t_stack **stack_a, int num);
int tmp_to_stack(t_stack **stack_a, char **tmp);
int arg_to_stack(int argc, char *argv[], t_stack **stack_a);

// free
void free_stack(t_stack **stack);
void	free_tmp(char **tmp);

// ft_split_multi
char	**ft_split_multi(char const *s, char *c);

// main
int init_stack(int argc, char *argv[], t_stack **stack_a);

// push_swap
int serch_min(t_stack **stack);
void get_pivot(t_stack **stack, int *pivot);
void separate_stack(t_stack **stack_a, t_stack **stack_b);
int count_step_a(t_stack **stack_a, int value);
int count_step_b(t_stack **stack_b, int tmp_step_b);
void get_min_step(t_stack **stack_a, t_stack **stack_b, int *step_a, int *step_b);
void do_rotate_a(t_stack **stack_a, int step_a);
void do_rotate_b(t_stack **stack_b, int step_b);
void sort6_to(t_stack **stack_a, t_stack **stack_b);
void push_swap(t_stack **stack_a, t_stack **stack_b);

// utils
int is_sorted(t_stack **stack);
int is_unique_node(t_stack **stack_a);
int stack_len(t_stack **stack);
int	is_intover(int sign, long res, long num);
int check_atoi(char *str, long *res);

// utils2
int ft_abs(int num);
void put_error(void);


void put_stack(t_stack *stack_a, t_stack *stack_b);

# endif