/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/19 19:15:52 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_lst(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}

// static void	init_stack(t_stack_node **stack)
// {
// 	(*stack)->nb = 0;
// 	(*stack)->index = 0;
// 	(*stack)->push_cost = 0;
// 	(*stack)->target_node = NULL;
// 	(*stack)->next = NULL;
// }

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc < 3)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (parse_number_n(argv, argc, &stack_a) != 0)
		return ((void)write(2, ERROR_MSG, ERROR_MSG_LEN), 1);

	sort(&stack_a, &stack_b);

	print_lst(stack_a);

	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (0);
}
