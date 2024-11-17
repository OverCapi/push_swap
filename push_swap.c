/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/17 06:18:45 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_lst(t_stack stack)
{
	t_list_ps	*cp;

	cp = stack.list;
	while (cp)
	{
		printf("%d\n", cp->nb);
		cp = cp->next;
	}
}

static void	init_stack(t_stack *stack)
{
	stack->list = NULL;
	stack->size = 0;
	stack->nb_instruction = 0;
}

int	main(int argc, char **argv)
{
	char	**argv_split;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 3)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 3)
	{
		if (argv && argv[1])
		{
			argv_split = ft_split(argv[1], ' ');
			if (!argv_split)
				return ((void)write(2, ERROR_MSG, ERROR_MSG_LEN), 1);
			if (parse_number_split(argv_split, &stack_a) != 0)
				return ((void)write(2, ERROR_MSG, ERROR_MSG_LEN), 1);
		}
	}
	else
		if (parse_number_n(argv, argc, &stack_a) != 0)
			return ((void)write(2, ERROR_MSG, ERROR_MSG_LEN), 1);
	print_lst(stack_a);
	ft_lstclear_ps(&stack_a.list, NULL);
	return (0);
}
