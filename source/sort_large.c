/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:22 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 14:47:24 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_node **a, t_node **b, int pivot, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*a)->value < pivot)
			pb(a, b);
		else
			case_rotate(a, b);
		i++;
	}
}

void	push_three(t_node **a, t_node **b)
{
	int	i;
	int	size;

	i = 0;
	while (i < 3 && *b != NULL)
	{
		size = stack_size(*b);
		rotate_to_index(b, find_max(b), size);
		pa(a, b);
		i++;
	}
}

void	sort_three(t_node **a, t_node **b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		case_swap(a, b);
	else if (first > second && second > third)
	{
		case_swap(a, b);
		case_reverse(a, b);
	}
	else if (first > second && second < third && first > third)
		case_rotate(a, b);
	else if (first < second && second > third && first < third)
	{
		case_swap(a, b);
		case_rotate(a, b);
	}
	else if (first < second && second > third && first > third)
		case_reverse(a, b);
}

void	handle_large(t_node **a, t_node **b, int size)
{
	while (size > 3)
	{
		quick_sort(a, b, partition(a, size, 4), size);
		size = stack_size(*a);
	}
	handle_small(a, b);
	while (*b != NULL)
	{
		push_three(a, b);
		sort_three(a, b);
	}
}

void	sort(t_node **a)
{
	int		size_a;
	t_node	*b;

	size_a = stack_size(*a);
	b = NULL;
	if (size_a <= 1 || *a == NULL || (*a)->next == NULL || is_sorted(a))
		return ;
	if (size_a == 2 || size_a == 3)
		handle_small(a, &b);
	else if (size_a == 4 || size_a == 5)
		handle_medium(a, &b);
	else if (size_a > 5)
		handle_large(a, &b, size_a);
	if (b != NULL)
		stack_clear(&b, pop);
}
