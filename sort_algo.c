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

void	merge(t_stack *stack_a, t_stack *stack_b, size_t size_a, size_t size_b)
{
	t_stack tmp;

	init_stack(&tmp);
	while (stack_a->list && stack_b->list && size_a > 0 && size_b > 0)
	{
		if (stack_a->list->nb <= stack_b->list->nb)
		{
			push(stack_a, &tmp);
			size_a--;
		}
		else
		{
			push(stack_b, &tmp);
			size_b--;
		}
	}
	while (size_a-- > 0)
		push(stack_a, &tmp);
	while (size_b-- > 0)
		push(stack_b, &tmp);
	while (tmp.size > 0)
		push(&tmp, stack_a);
	ft_lstclear_ps(&tmp.list, NULL);
}

void	merge_sort_recursion(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	size_t	i;
	size_t	mid;

	if (size <= 1)
		return ;
	i = 0;
	mid = size / 2;
	while (i++ < mid)
		push(stack_a, stack_b);
	merge_sort_recursion(stack_a, stack_b, mid);
	merge_sort_recursion(stack_b, stack_a, size - mid);
	merge(stack_a, stack_b, mid + 1, size - mid);
}

void	merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	merge_sort_recursion(stack_a, stack_b, stack_a->size);
}
