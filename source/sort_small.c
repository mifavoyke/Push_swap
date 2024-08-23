/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:34 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 14:47:35 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node **stack)
{
	t_node	*tmp;

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

void	handle_small(t_node **a, t_node **b)
{
	while (is_sorted(a) != true)
	{
		case_swap(a, b);
		if (!is_sorted(a))
			case_reverse(a, b);
	}
}

void	handle_medium(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	quick_sort(a, b, partition(a, size, 2), size);
	handle_small(a, b);
	while (*b != NULL)
		pa(a, b);
	if (!is_sorted(a))
		case_swap(a, b);
	while (!is_sorted(a))
		case_rotate(a, b);
}
