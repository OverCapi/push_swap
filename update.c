/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:13:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:45:42 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_index_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				median;
	int				index;

	index = 0;
	tmp = *stack;
	median = get_size(*stack) / 2;
	while (*stack)
	{
		(*stack)->index = index;
		if (index <= median)
			(*stack)->median = 0;
		else
			(*stack)->median = 1;
		index++;
		*stack = (*stack)->next;
	}
	*stack = tmp;
}

void	update(t_stack_node **A, t_stack_node **B, int index)
{
	if (index == 1)
	{
		update_index_stack(A);
		update_index_stack(B);
		return ;
	}
	update_index_stack(A);
	update_index_stack(B);
	update_target_node(A, *B);
	update_cost_push(A, *B);
}
