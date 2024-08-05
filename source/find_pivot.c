#include "push_swap.h"

static int *stack_to_array(t_node **stack, int size)
{
    int *result;
    t_node *tmp;
    int i;

    if (stack == NULL || *stack == NULL)
        return (NULL);
    result = (int *)malloc(sizeof(int) * size);
    if (result == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        result[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    return (result);
}

static int *bubble_sort(int *value, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (value[j] > value[j + 1])
            {
                tmp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    return (value);
}

int find_quarter(t_node **stack, int size)
{
    int result;
    int *array;

    array = stack_to_array(stack, size);
    bubble_sort(array, size);
    result = array[size / 4];
    free(array);
    return (result);
}
