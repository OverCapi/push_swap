/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:10:40 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:12:48 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *A)
{
	while (A->next)
	{
		if (A->nb > A->next->nb)
			return (0);
		A = A->next;
	}
	return (1);
}

int	get_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	sort_three(t_stack_node **A)
{
	if ((*A)->nb > (*A)->next->nb && (*A)->nb > (*A)->next->next->nb)
		rotate(A, 'a');
	else if ((*A)->next->nb > (*A)->nb && (*A)->next->nb > (*A)->next->next->nb)
		reverse_rotate(A, 'a');
	if ((*A)->nb > (*A)->next->nb)
		swap(A, 'a');
}

t_stack_node	*get_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;

	min_node = stack;
	while (stack)
	{
		if (min_node->nb > stack->nb)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*get_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;

	max_node = stack;
	while (stack)
	{
		if (max_node->nb < stack->nb)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
