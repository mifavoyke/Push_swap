/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:23:53 by yhusieva          #+#    #+#             */
/*   Updated: 2024/08/12 13:23:54 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/Include/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* PIVOT */
int		partition(t_node **stack, int size, int part);

/* Push Pop */
void	push(t_node **top, int value);
int		pop(t_node **top);

/* CENTRAL FUNCTION */
void	sort(t_node **a);

/* Handle Large */
void	quick_sort(t_node **a, t_node **b, int pivot, int size);
void	handle_large(t_node **a, t_node **b, int size);
void	push_three(t_node **a, t_node **b);
void	sort_three(t_node **a, t_node **b);
int		find_max(t_node **stack);
void	rotate_to_index(t_node **b, int index, int size);

/* Handle Small */
bool	is_sorted(t_node **stack);
void	handle_small(t_node **a, t_node **b);
void	handle_medium(t_node **a, t_node **b);

/* CASES */
void	case_swap(t_node **a, t_node **b);
void	case_rotate(t_node **a, t_node **b);
void	case_reverse(t_node **a, t_node **b);

/* OPERATIONS */
void	sa(t_node **top);
void	sb(t_node **top);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **top_a, t_node **top_b);
void	pb(t_node **top_a, t_node **top_b);
void	ra(t_node **top);
void	rb(t_node **top);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **top);
void	rrb(t_node **top);
void	rrr(t_node **stack_a, t_node **stack_b);

/* Utils */
int		stack_size(t_node *stack);
t_node	*create_node(int value);
void	stack_add_front(t_node **top, t_node *newnode);
void	del_node(t_node **node);
void	stack_clear(t_node **top, int (*pop)(t_node **));

// void print_stack(t_node *head);

/* Handle Errors */
bool	has_duplicates(int *arr, int size);
bool	is_integer(char *str);

/* Main utils */
char	**parse_input(int argc, char *argv[], int *count);
int		*parse_arguments(char *numbers[], int count, int argc);
void	populate_stack(t_node **stack_a, int *args, int size);
void	ft_error(void *args);
void	cleanup(int argc, char **numbers, int count);

#endif
