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

// check
int is_sorted(t_stack **stack);
int is_unique_node(t_stack **stack_a);
int stack_len(t_stack **stack);
int	is_intover(int sign, long res, long num);
int check_atoi(char *str, long *res);

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
void put_error(void);
int init_stack(int argc, char *argv[], t_stack **stack_a);

// push_swap
void sort_3_a(t_stack **stack_a);
int serch_med_5(t_stack **stack);
void sort_4_a(t_stack **stack_a, t_stack **stack_b);
void sort_5(t_stack **stack_a, t_stack **stack_b);
int serch_min(t_stack **stack);
//void set_min_max(t_stack **stack_a, int max, int min);
void partition_stack(t_stack **stack_a, t_stack **stack_b, int pivot);
void quick_sort(t_stack **stack_a, t_stack **stack_b, int len);
void push_swap(t_stack **stack_a, t_stack **stack_b);


# endif