#include "push_swap.h"

void push(t_node **top, int value)
{
    t_node *tmp;

    tmp = create_node(value);
    if (tmp != NULL)
        stack_add_front(top, tmp);
}

int pop(t_node **top)
{
    t_node *tmp;
    int value;

    if (top == NULL || *top == NULL)
        return (1);
    tmp = *top;
    value = tmp->value;
    *top = tmp->next;
    del_node(&tmp);
    return (value);
}
