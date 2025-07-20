/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:23:49 by yhusieva          #+#    #+#             */
/*   Updated: 2025/07/20 17:50:21 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	int		*args;
	char	**numbers;
	int		count;

	if (argc <= 1)
		return (0);
	numbers = parse_input(argc, argv, &count);
	if (numbers == NULL)
		return (1);
	args = parse_arguments(numbers, count, argc);
	if (args == NULL)
		return (1);
	if (has_duplicates(args, count))
	{
		cleanup(argc, numbers, count);
		ft_error(args);
	}
	stack_a = NULL;
	populate_stack(&stack_a, args, count);
	free(args);
	ft_printf("Operations:\n");
	sort(&stack_a);
	ft_printf("Sorted stack:\n");
	stack_print(stack_a);
	stack_clear(&stack_a, pop);
	cleanup(argc, numbers, count);
	return (0);
}
