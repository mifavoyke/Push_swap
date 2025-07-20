/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:20:55 by yhusieva          #+#    #+#             */
/*   Updated: 2025/07/20 17:45:55 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **top)
{
	int	first;
	int	second;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = pop(top);
	second = pop(top);
	push(top, first);
	push(top, second);
}

void	sa(t_node **top)
{
	swap(top);
	ft_printf("sa\n");
}

void	sb(t_node **top)
{
	swap(top);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
