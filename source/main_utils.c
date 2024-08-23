/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:19:15 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:19:17 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_input(int argc, char *argv[], int *count)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (numbers == NULL)
			return (NULL);
		*count = 0;
		while (numbers[*count] != NULL)
			(*count)++;
	}
	else
	{
		numbers = argv + 1;
		*count = argc - 1;
	}
	return (numbers);
}

int	*parse_arguments(char *numbers[], int count, int argc)
{
	int	*args;
	int	i;

	args = (int *)malloc(count * sizeof(int));
	if (args == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!is_integer(numbers[i]))
		{
			cleanup(argc, numbers, count);
			ft_error(args);
		}
		args[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (args);
}

void	populate_stack(t_node **stack_a, int *args, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		push(stack_a, args[i]);
		i--;
	}
}

void	ft_error(void *args)
{
	ft_printf("Error\n");
	if (args != NULL)
		free(args);
	exit(0);
}

void	cleanup(int argc, char **numbers, int count)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (i < count)
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
}
