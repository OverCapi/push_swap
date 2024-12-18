/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:50:44 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 02:57:02 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_newstack(int nb)
{
	t_stack_node	*stack;

	stack = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack)
		return (NULL);
	stack->nb = nb;
	stack->index = 0;
	stack->median = 0;
	stack->push_cost = 0;
	stack->next = NULL;
	stack->target_node = NULL;
	return (stack);
}
