/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:42 by yhusieva          #+#    #+#             */
/*   Updated: 2025/07/20 17:49:22 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*create_node(int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		ft_printf("Error malloc create_node");
		return (NULL);
	}
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

void	stack_add_front(t_node **top, t_node *newnode)
{
	newnode->next = *top;
	*top = newnode;
}

void	del_node(t_node **node)
{
	if (node != NULL)
	{
		free(*node);
		*node = NULL;
	}
}

void	stack_clear(t_node **top, int (*pop)(t_node **))
{
	if (top == NULL || *top == NULL || pop == NULL)
		return ;
	while (*top != NULL)
		pop(top);
}

void	stack_print(t_node *stack)
{
	t_node	*current;

	if (stack == NULL)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	current = stack;
	while (current != NULL)
	{
		ft_printf("%d", current->value);
		if (current->next != NULL)
			ft_printf(" ");
		current = current->next;
	}
	ft_printf("\n");
}
