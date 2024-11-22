/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:05:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:29:16 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_closest_big(t_stack_node *A, t_stack_node *node)
{
	t_stack_node	*tnode;
	t_stack_node	*tmp;

	tnode = NULL;
	tmp = A;
	while (A)
	{
		if (A->nb > node->nb && (!tnode || tnode->nb > A->nb))
			tnode = A;
		A = A->next;
	}
	if (!tnode)
		return (get_min_node(tmp));
	return (tnode);
}

static t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *B)
{
	t_stack_node	*tnode;
	t_stack_node	*tmp;

	tnode = NULL;
	tmp = B;
	while (B)
	{
		if (B->nb < node->nb && (!tnode || tnode->nb < B->nb))
			tnode = B;
		B = B->next;
	}
	if (!tnode)
		return (get_max_node(tmp));
	return (tnode);
}

void	update_target_node(t_stack_node **A, t_stack_node *B)
{
	t_stack_node	*tmp;

	tmp = *A;
	while (*A)
	{
		(*A)->target_node = get_target_node(*A, B);
		*A = (*A)->next;
	}
	*A = tmp;
}
