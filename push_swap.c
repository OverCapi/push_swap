/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:19:51 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	return (0);
}
