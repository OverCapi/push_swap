/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:49:10 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/14 18:20:33 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*copy_tab(t_stack stack)
{
	int		*array;
	size_t	i;

	i = 0;
	array = (int *)malloc((stack.size + 1) * sizeof(int));
	if (!array)
		return (NULL);
	while (stack.list)
	{
		array[i++] = stack.list->nb;
		stack.list = stack.list->next;
	}
	return (array);
}

static int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int		pivot;

	i = start - 1;
	pivot = array[end];
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			int_swap(&array[i], &array[j]);
		}
		j++;
	}
	int_swap(&array[i + 1], &array[end]);
	return (i + 1);
}

static void	quick_sort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		quick_sort(array, start, pivot_index - 1);
		quick_sort(array, pivot_index + 1, end);
	}
}

static size_t	search_element(t_stack stack, int element)
{
	size_t	index;

	index = 0;
	while (stack.list)
	{
		if (element == stack.list->nb)
			break ;
		index++;
		stack.list = stack.list->next;
	}
	return (index);
}

static void	do_instruction(t_stack *stack_a, t_stack *stack_b, size_t index)
{
	size_t	i;

	i = 0;
	if (index == 0)
		return ((void)push(stack_a, stack_b));
	else if (index == 1)
		swap(stack_a);
	else if (index <= (stack_a->size) / 2)
	{
		while (i < index)
		{
			rotate(stack_a);
			i++;
		}
	}
	else
	{
		while (i < stack_a->size - index)
		{
			reverse_rotate(stack_a);
			i++;
		}
	}
	return ((void)push(stack_a, stack_b));
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *array)
{
	size_t	array_size;
	size_t	i;
	size_t	index;

	i = 0;
	(void)stack_b;
	array_size = stack_a->size;
	while (i < array_size - 1)
	{
		index = search_element(*stack_a, array[i]);
		do_instruction(stack_a, stack_b, index);
		i++;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int *array;

	array = copy_tab(*stack_a);
	if (!array)
		return ;
	quick_sort(array, 0, stack_a->size - 1);
	sort_stack(stack_a, stack_b, array);
	while (stack_b->list)
		push(stack_b, stack_a);
	free(array);
}
