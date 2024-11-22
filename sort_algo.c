/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:55 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:26:56 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_to_a(t_stack_node **A, t_stack_node **B)
{
	(*B)->target_node = get_closest_big(*A, *B);
	if ((*B)->target_node->median == 0)
		while ((*A)->nb != (*B)->target_node->nb)
			rotate(A, 'a');
	else
		while ((*A)->nb != (*B)->target_node->nb)
			reverse_rotate(A, 'a');
	push(B, A, 'a');
}

int	check_simple_sort(t_stack_node **A, t_stack_node **B)
{
	int	size_a;

	size_a = get_size(*A);
	if (size_a == 2)
		return ((void)swap(A, 'a'), 1);
	else if (size_a == 3)
		return ((void)sort_three(A), 1);
	else if (size_a > 4)
		push(A, B, 'b');
	return (0);
}

void	rotate_stack(t_stack_node **A)
{
	t_stack_node	*min;

	min = get_min_node(*A);
	if (min->median == 0)
		while ((*A)->nb != min->nb)
			rotate(A, 'a');
	else
		while ((*A)->nb != min->nb)
			reverse_rotate(A, 'a');
}

void	sort(t_stack_node **A, t_stack_node **B)
{
	if (is_sorted(*A))
		return ;
	if (check_simple_sort(A, B) == 1)
		return ;
	push(A, B, 'b');
	while (get_size(*A) > 3)
	{
		update(A, B, 0);
		move_to_b(A, B);
	}
	if (!is_sorted(*A))
		sort_three(A);
	while (get_size(*B) > 0)
	{
		update(A, B, 1);
		move_to_a(A, B);
	}
	if (!is_sorted(*A))
		rotate_stack(A);
}
