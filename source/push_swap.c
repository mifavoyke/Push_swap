#include "push_swap.h"

static void ft_error(int *args)
{
    printf("Error\n");
    if (args != NULL)
        free(args);
    exit(0);
}

static void populate_stack(t_node **stack_a, int *args, int size)
{
    int i;

    i = size - 1;
    while (i >= 0)
    {
        push(stack_a, args[i]);
        i--;
    }
}

static int *parse_arguments(int argc, char *argv[])
{
    int *args;
    int i;

    args = (int *)malloc((argc - 1) * sizeof(int));
    if (args == NULL)
        ft_error(args);
    i = 1;
    while (i < argc)
    {
        if (!is_integer(argv[i]))
            ft_error(args);
        args[i - 1] = atoi(argv[i]);
        i++;
    }
    return (args);
}

int main(int argc, char *argv[])
{
    t_node *stack_a;
    int *args;

    if (argc <= 1)
        return (0);
    // if (argc == 2)
    //     args = 
    args = parse_arguments(argc, argv);
    if (args == NULL)
        return (1);
    if (has_duplicates(args, argc - 1))
        ft_error(args);
    stack_a = NULL;
    populate_stack(&stack_a, args, argc - 1);
    free(args);
    sort(&stack_a);
    stack_clear(&stack_a, pop);
    return (0);
}

/*
printf("stack a after: ");
print_stack(stack_a);
printf("stack b after: ");
print_stack(stack_b);

print_stack(*a);
print_stack(*b);

#include <signal.h>
printf("%d\n", getpid());
pause();
*/
