/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:20:48 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:20:50 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **top)
{
	t_node	*current;
	t_node	*previous;

	current = *top;
	previous = NULL;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	if (previous != NULL)
		previous->next = NULL;
	current->next = *top;
	*top = current;
}

void	rra(t_node **top)
{
	reverse_rotate(top);
	ft_printf("rra\n");
}

void	rrb(t_node **top)
{
	reverse_rotate(top);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
