/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:44:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/20 17:36:23 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (!stack && !new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
}
