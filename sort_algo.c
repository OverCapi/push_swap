/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:13:45 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/18 16:40:36 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->list = NULL;
	stack->size = 0;
	stack->nb_instruction = 0;
}

static int	is_sorted(t_stack *stack)
{
	t_list_ps	*cp;

	cp = stack->list;
	while (cp->next)
	{
		if (cp->nb > cp->next->nb)
			return (0);
		cp = cp->next;
	}
	return (1);
}


static int	get_size(t_stack_node *stack)
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

static t_stack_node	*get_min_node(t_stack_node *stack)
{
	t_stack_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static t_stack_node	*get_max_node(t_stack_node *stack)
{
	t_stack_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->nb > max->nb)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

static t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *stack_b)
{
	t_stack_node	*target_node;

	target_node = get_max_node(stack_b);
	while (stack_b)
	{
		if (node->nb > stack_b->nb)
			return (target_node);
		stack_b = stack_b->next;
	}
	return (target_node);
}

static void	update_target_node(t_stack_node **stack_a, t_stack_node *stack_b)
{
	t_stack_node	*tmp_a;

	tmp_a = *stack_a;
	while (*stack_a)
	{
		(*stack_a)->target_node = get_target_node(*stack_a, stack_b);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp_a
}

static void	update_cost_push(t_stack_node **stack_a, t_stack_node *stack_b)
{
	t_stack_node	*tmp_a;
	int				size_a;
	int				size_b;

	tmp_a = *stack_a;
	size_a = get_size(*stack_a);
	size_b = get_size(stack_b);
	while (*stack_a)
	{
		if ((*stack_a)->index <= size_a / 2)
			(*stack_a)->push_cost = (*stack_a)->index;
		else
			(*stack_a)->push_cost = size_a - (*stack_a)->index;
		if ((*stack_a)->target_node->index <= size_a / 2)
			(*stack_a)->push_cost += (*stack_a)->index;
		else
			(*stack_a)->push_cost += size_a - (*stack_a)->index;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a) = tmp_a;
}

static int	get_cheapest_index(t_stack_node *stack_a)
{
	t_stack_node	*cheapest;

	cheapest = stack_a;
	while (stack_a)
	{
		if (stack_a->push_cost < cheapest->push_cost)
			cheapest = stack_a;
		else if (stack_a->push_cost == 0)
			return (stack_a->index);
		stack_a = stack_a->next;
	}
	return (cheapest->index);
}

static void	prep_push(t_stack_node **stack_a, t_stack_node **stack_b, int index)
{
	
}

void	sort(t_stack_node *stack_a, t_stack_node *stack_b)
{
	// int	min_b;
	// int	max_b;
	int		index;

	if (is_sorted(stack_a))
		return ;
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	// min_b = get_min_node(stack_b)->nb;
	// max_b = get_max_node(stack_b)->nb;
	while (get_size(size_a) > 3)
	{
		update_target_node(&stack_a, stack_b);
		update_cost_push(&stack_a, stack_b);
		index = get_cheapest_index(stack_a);
		prep_push(&stack_a, &stack_b, index);
	}
}
