/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:13:45 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 16:50:05 by llemmel          ###   ########.fr       */
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

void	update_index_stack(t_stack_node **stack)
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

t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *B)
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
		// ft_printf("premier calcule : %d, (index : %d, size : %d)\n", (*A)->push_cost, (*A)->index, get_size(*A));
		if ((*A)->target_node->median == 0)
			(*A)->push_cost += (*A)->target_node->index;
		else
			(*A)->push_cost += get_size(B) - (*A)->target_node->index;
		// ft_printf("cost push of %d : %d (target : %d)\n", (*A)->nb, (*A)->push_cost, (*A)->target_node->nb);
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

void	move_to_b(t_stack_node **A, t_stack_node **B)
{
	t_stack_node	*cheap;

	cheap = get_cheapest_node(*A);
	if (cheap->median == 0 && cheap->target_node->median == 0)
		while ((*A)->nb != cheap->nb && (*B)->nb != cheap->target_node->nb)
			rotate_double(A, B);
	else if (cheap->median == 1 && cheap->target_node->median == 1)
		while ((*A)->nb != cheap->nb && (*B)->nb != cheap->target_node->nb)
			reverse_rotate_double(A, B);
	if (cheap->median == 0)
		while (cheap->nb != (*A)->nb)
			rotate(A, 'a');
	else
		while (cheap->nb != (*A)->nb)
			reverse_rotate(A, 'a');
	if (cheap->target_node->median == 0)
		while (cheap->target_node->nb != (*B)->nb)
			rotate(B, 'b');
	else
		while (cheap->target_node->nb != (*B)->nb)
			reverse_rotate(B, 'b');
	push(A, B, 'b');
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

void	move_to_a(t_stack_node **A, t_stack_node **B)
{
	if ((*B)->target_node->median == 0)
		while ((*A)->nb != (*B)->target_node->nb)
			rotate(A, 'a');
	else
		while ((*A)->nb != (*B)->target_node->nb)
			reverse_rotate(A, 'a');
	push(B, A, 'a');
}

void	sort(t_stack_node **A, t_stack_node **B)
{
	int	size_a;
	t_stack_node	*min;

	if (is_sorted(*A))
		return ;
	size_a = get_size(*A);
	if (size_a == 2)
		return (swap(A, 'a'));
	else if (size_a == 3)
		return (sort_three(A));
	else if (size_a > 4)
		push(A, B, 'b');
	push(A, B, 'b');
	while (get_size(*A) > 3)
	{
		update_index_stack(A);
		update_index_stack(B);
		update_target_node(A, *B);
		update_cost_push(A, *B);
		move_to_b(A, B);
	}
	if (!is_sorted(*A))
		sort_three(A);
	while (get_size(*B) > 0)
	{
		update_index_stack(A);
		update_index_stack(B);
		(*B)->target_node = get_closest_big(*A, *B);
		move_to_a(A, B);
	}
	if (!is_sorted(*A))
	{
		min = get_min_node(*A);
		if (min->median == 0)
			while ((*A)->nb != min->nb)
				rotate(A, 'a');
		else
			while ((*A)->nb != min->nb)
				reverse_rotate(A, 'a');
	}
}
