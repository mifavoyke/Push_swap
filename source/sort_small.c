#include "push_swap.h"

bool is_sorted(t_node **stack)
{
    t_node *tmp;

    tmp = *stack;
    if (tmp == NULL || tmp->next == NULL)
        return (true);
    while (tmp->next != NULL)
    {
        if (tmp->value > tmp->next->value)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

void handle_small(t_node **a, t_node **b)
{
    while (is_sorted(a) != true)
    {
        case_swap(a, b);
        if (is_sorted(a) == false)
            case_reverse(a, b);
    }
}
