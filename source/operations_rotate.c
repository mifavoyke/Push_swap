/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:20:42 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:20:43 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **top)
{
	t_node	*first_node;
	t_node	*last_node;

	if ((*top)->next == NULL || *top == NULL)
		return ;
	first_node = *top;
	*top = first_node->next;
	first_node->next = NULL;
	last_node = *top;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
}

void	ra(t_node **top)
{
	rotate(top);
	ft_printf("ra\n");
}

void	rb(t_node **top)
{
	rotate(top);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
