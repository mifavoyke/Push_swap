#include "push_swap.h"

int find_max(t_node **stack)
{
    t_node *tmp;
    int max;
    int i;
    int max_index;

    if (*stack == NULL || (*stack)->next == NULL)
        return (0);
    tmp = *stack;
    max = (*stack)->value;
    i = 0;
    max_index = 0;
    while (tmp != NULL)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
            max_index = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (max_index);
}

void rotate_to_index(t_node **stack, int index, int size)
{
    int i;
    int half;

    if (*stack == NULL)
        return ;
    half = size / 2;
    i = 0;
    if (index < half)
    {
        while (i < index)
        {
            rb(stack);
            i++;
        }
    }
    else
    {
        while (i < size - index)
        {
            rrb(stack);
            i++;
        }
    }
}
