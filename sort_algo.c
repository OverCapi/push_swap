/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:13:45 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/21 01:45:42 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
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
	t_stack_node	*tnode;
	t_stack_node	*tmp;

	tnode = NULL;
	tmp = stack_b;
	while (tmp)
	{
		if (node->nb < tmp->nb && (!tnode || tnode->nb > tmp->nb))
			tnode = tmp;
		tmp = tmp->next;
	}
	if (!tnode)
		tnode = get_max_node(stack_b);
	return (tnode);
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
	*stack_a = tmp_a;
}

static int	get_index(t_stack_node *stack, int nb)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->nb == nb)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

// modif pour utiliser calculer les double operation (rr rrr)
static void	update_cost_push(t_stack_node **stack_a, t_stack_node *stack_b)
{
	t_stack_node	*tmp_a;
	int				size_a;
	int				size_b;
	int				index;
	int				index_2;

	tmp_a = *stack_a;
	size_a = get_size(*stack_a);
	size_b = get_size(stack_b);
	index = 0;
	while (*stack_a)
	{
		if (index <= size_a / 2)
			(*stack_a)->push_cost = index;
		else
			(*stack_a)->push_cost = size_a - index;
		index_2 = get_index(stack_b, (*stack_a)->target_node->nb);
		if (index_2 <= size_b / 2)
			(*stack_a)->push_cost += index_2;
		else
			(*stack_a)->push_cost += size_b - index_2;
		*stack_a = (*stack_a)->next;
		index++;
	}
	(*stack_a) = tmp_a;
}

static int	get_cheapest_index(t_stack_node *stack_a, int *cheapest_nb)
{
	t_stack_node	*cheapest;
	int				min_index;
	int				index;

	cheapest = stack_a;
	*cheapest_nb = stack_a->nb;
	index = 0;
	min_index = 0;
	while (stack_a)
	{
		if (stack_a->push_cost < cheapest->push_cost)
		{
			*cheapest_nb = stack_a->nb;
			cheapest = stack_a;
			min_index = index;
		}
		else if (stack_a->push_cost == 0)
		{
			*cheapest_nb = stack_a->nb;
			return (index);
		}
		index++;
		stack_a = stack_a->next;
	}
	return (min_index);
}

static t_stack_node	*get_close_big(t_stack_node *stack_a, t_stack_node *node)
{
	t_stack_node	*tnode;
	t_stack_node	*tmp;

	tnode = NULL;
	tmp = stack_a;
	while (tmp)
	{
		if (node->nb < tmp->nb && (!tnode || tnode->nb > tmp->nb))
			tnode = tmp;
		tmp = tmp->next;
	}
	if (!tnode)
		tnode = get_min_node(stack_a);
	return (tnode);
}

// modif pour utiliser les double operation (rr rrr)
static void	prep_push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int		index;
	int		nb;
	void	(*fct)(t_stack_node **, char);

	index = get_cheapest_index(*stack_a, &nb);
	if (index <= get_size(*stack_a) / 2)
		fct = &rotate;
	else
		fct = &reverse_rotate;
	while ((*stack_a)->nb != nb)
		fct(stack_a, 'a');
	index = get_index(*stack_b, (*stack_a)->target_node->nb);
	if (index <= get_size(*stack_b) / 2)
		fct = &rotate;
	else
		fct = &reverse_rotate;
	while ((*stack_b)->nb != (*stack_a)->target_node->nb)
		fct(stack_b, 'b');
}

static void	prep_push_2(t_stack_node **stack_a, t_stack_node *node)
{
	int		index;
	void	(*fct)(t_stack_node **, char);

	index = get_index(*stack_a, node->target_node->nb);
	if (index <= get_size(*stack_a) / 2)
		fct = &rotate;
	else
		fct = &reverse_rotate;
	while ((*stack_a)->nb != node->target_node->nb)
		fct(stack_a, 'a');
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*min;
	t_stack_node	*max;

	min = get_min_node(*stack);
	max = get_max_node(*stack);
	if ((*stack)->nb == min->nb)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if ((*stack)->nb == max->nb)
	{
		rotate(stack, 'a');
		if (!((*stack)->nb == min->nb))
			swap(stack, 'a');
	}
	else
	{
		if ((*stack)->next->nb == min->nb)
			swap(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
}

void	sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (get_size(*stack_a) > 3)
	{
		update_target_node(stack_a, *stack_b);
		update_cost_push(stack_a, *stack_b);
		prep_push(stack_a, stack_b);
		push(stack_a, stack_b, 'b');
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (get_size(*stack_b) > 0)
	{
		(*stack_b)->target_node = get_close_big(*stack_a, *stack_b);
		// ft_printf("target node of %d : %d\n", (*stack_b)->nb, (*stack_b)->target_node->nb);
		prep_push_2(stack_a, *stack_b);
		push(stack_b, stack_a, 'a');
	}
	int i;
	if (get_index(*stack_a, get_min_node(*stack_a)->nb) <= get_size(*stack_a) / 2)
		i = 0;
	else
		i = 1;
	while (!is_sorted(*stack_a))
	{
		if (i == 0)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}
