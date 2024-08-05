#include "push_swap.h"

static void push_stack(t_node **stack_1, t_node **stack_0)
{
    t_node *tmp;

    if (stack_0 == NULL || *stack_0 == NULL)
        return ;
    tmp = *stack_0;
    push(stack_1, tmp->value);
    *stack_0 = tmp->next;
    pop(&tmp);
}

void pa(t_node **top_a, t_node **top_b)
{
    push_stack(top_a, top_b);
    printf("pa\n");
}

void pb(t_node **top_a, t_node **top_b)
{
    push_stack(top_b, top_a);
    printf("pb\n");
}
