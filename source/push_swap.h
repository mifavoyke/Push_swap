#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
# include "../ft_printf/Include/ft_printf.h"

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

/* PIVOT */
int find_quarter(t_node **stack, int size);

/* Push Pop */
void push(t_node **top, int value);
int pop(t_node **top);

/* CENTRAL FUNCTION */
void sort(t_node **a);

/* Handle Large */
void quick_sort(t_node **a, t_node **b, int pivot, int size);
void handle_large(t_node **a, t_node **b, int size);
void push_three(t_node **a, t_node **b);
void sort_three(t_node **a, t_node **b);
int find_max(t_node **stack);
void rotate_to_index(t_node **b, int index, int size);

/* Handle Small */
void handle_small(t_node **a, t_node **b);
bool is_sorted(t_node **stack);

/* CASES */
void case_swap(t_node **a, t_node **b);
void case_rotate(t_node **a, t_node **b);
void case_reverse(t_node **a, t_node **b);

/* OPERATIONS */
void sa(t_node **top);
void sb(t_node **top);
void ss(t_node **stack_a, t_node **stack_b);
void pa(t_node **top_a, t_node **top_b);
void pb(t_node **top_a, t_node **top_b);
void ra(t_node **top);
void rb(t_node **top);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **top);
void rrb(t_node **top);
void rrr(t_node **stack_a, t_node **stack_b);

/* Utils */
int	stack_size(t_node *stack);
t_node *create_node(int value);
void stack_add_front(t_node **top, t_node *newnode);
void del_node(t_node **node);
void stack_clear(t_node **top, int (*pop)(t_node **));

// void print_stack(t_node *head);

/* Handle Errors */
bool has_duplicates(int *arr, int size);
bool is_integer(char *str);
const char *skip_whitespace(const char *str);
int handle_sign(const char **str);
void calculate_cutoff(int neg, unsigned long *cutoff, int *cutlim);
void handle_out_of_range(int neg, unsigned long *acc);
void set_endptr(const char **str, char **endptr, int any, const char *original_str);

#endif