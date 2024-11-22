/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:07:48 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:29:29 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost_push(t_stack_node **A, t_stack_node *B)
{
	t_stack_node	*tmp;

	tmp = *A;
	while (*A)
	{
		if ((*A)->median == 0)
			(*A)->push_cost = (*A)->index;
		else
			(*A)->push_cost = get_size(tmp) - (*A)->index;
		if ((*A)->target_node->median == 0)
			(*A)->push_cost += (*A)->target_node->index;
		else
			(*A)->push_cost += get_size(B) - (*A)->target_node->index;
		*A = (*A)->next;
	}
	*A = tmp;
}

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (cheapest->push_cost > stack->push_cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}
