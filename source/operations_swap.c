#include "push_swap.h"

static void swap(t_node **top)
{
    int first;
    int second;

    if (*top == NULL || (*top)->next == NULL)
        return ;
    first = pop(top);
    second = pop(top);
    push(top, first);
    push(top, second);
}

void sa(t_node **top)
{
    swap(top);
    printf("sa\n");
}

void sb(t_node **top)
{
    swap(top);
    printf("sb\n");
}

void ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}
