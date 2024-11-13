/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 12:29:03 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_stack stack_a, t_stack stack_b)
{
	size_t	i;

	i = 0;
	t_list	*cp_a = stack_a.list;
	t_list	*cp_b = stack_b.list;
	printf("-------------------------------------------------------------------\n");
	while (cp_a && cp_b)
	{
		printf("%d			%d\n", *(int *)cp_a->content, *(int *)cp_b->content);
		cp_a = cp_a->next;
		cp_b = cp_b->next;
	}
	printf("-------------------------------------------------------------------\n");
}

void	del(void *ctn)
{
	ctn = NULL;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack	stack_a = (t_stack){
		.list = NULL,
		.size = 0
	};
	t_stack	stack_b = (t_stack){
		.list = NULL,
		.size = 0
	};
	size_t	i;

	i = 1;
	int	tab[11] =  {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	tab2[11] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
	stack_a.list = ft_lstnew(&tab[0]);
	stack_a.size = 11;
	stack_b.list = ft_lstnew(&tab2[0]);
	stack_b.size = 11;
	while (i < stack_a.size)
	{
		ft_lstadd_back(&stack_a.list, ft_lstnew(&tab[i]));
		ft_lstadd_back(&stack_b.list, ft_lstnew(&tab2[i]));
		i++;
	}

	print_list(stack_a, stack_b);

	push(&stack_a, &stack_b);

	print_list(stack_a, stack_b);

	ft_lstclear(&stack_a.list, &del);
	ft_lstclear(&stack_b.list, &del);
	return (0);
}
