/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:13:43 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:13:46 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_swap(t_node **a, t_node **b)
{
	bool	a_is_unordered;
	bool	b_is_unordered;

	a_is_unordered = (*a != NULL && (*a)->next != NULL
			&& (*a)->value > (*a)->next->value);
	b_is_unordered = (*b != NULL && (*b)->next != NULL
			&& (*b)->value < (*b)->next->value);
	if (a_is_unordered && b_is_unordered)
		ss(a, b);
	else if (a_is_unordered)
		sa(a);
	else if (b_is_unordered)
		sb(b);
}

void	case_rotate(t_node **a, t_node **b)
{
	int		max;
	int		size;
	bool	a_is_unordered;
	bool	b_is_unordered;

	max = find_max(b);
	size = stack_size(*b);
	a_is_unordered = (*a != NULL && (*a)->next != NULL
			&& is_sorted(a) == false);
	b_is_unordered = (*b != NULL && (*b)->next != NULL
			&& max > 0 && max < size / 2);
	if (a_is_unordered && b_is_unordered)
		rr(a, b);
	else if (a_is_unordered)
		ra(a);
	else if (b_is_unordered)
		rb(b);
}

void	case_reverse(t_node **a, t_node **b)
{
	int		max;
	int		size;
	bool	a_is_unordered;
	bool	b_is_unordered;

	max = find_max(b);
	size = stack_size(*b);
	a_is_unordered = (*a != NULL && (*a)->next != NULL
			&& is_sorted(a) == false);
	b_is_unordered = (*b != NULL && (*b)->next != NULL
			&& max < size && max > size / 2);
	if (a_is_unordered && b_is_unordered)
		rrr(a, b);
	else if (a_is_unordered)
		rra(a);
	else if (b_is_unordered)
		rrb(b);
}
