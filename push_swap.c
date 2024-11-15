/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/15 16:05:00 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_stack stack_a, t_stack stack_b)
{
	size_t	i;

	i = 0;
	t_list_ps	*cp_a = stack_a.list;
	t_list_ps	*cp_b = stack_b.list;
	while (cp_a && cp_b)
	{
		printf("%d	|	%d\n", cp_a->nb, cp_b->nb);
		cp_a = cp_a->next;
		cp_b = cp_b->next;
	}
	while (cp_a)
	{
		printf("%d	|\n", cp_a->nb);
		cp_a = cp_a->next;
	}
	while (cp_b)
	{
		printf("  	|	%d\n", cp_b->nb);
		cp_b = cp_b->next;
	}
	printf("stack_a | stack_b\n");
	printf("-------------------------------------------------------------------\n");
}

void	del(int *nb)
{
	*nb = 0;
}

t_list_ps	*ft_lstnew_ps(int nb)
{
	t_list_ps	*lst;

	lst = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!lst)
		return (NULL);
	lst->nb = nb;
	lst->next = NULL;
	return (lst);
}

t_list_ps	*ft_lstlast_ps(t_list_ps *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*lstlast;

	if (!lst && !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		lstlast = ft_lstlast_ps(*lst);
		lstlast->next = new;
	}
}

void	ft_lstdelone_ps(t_list_ps *lst, void (*del)(int *))
{
	if (!lst || !del)
		return ;
	del(&lst->nb);
	free(lst);
}

void	ft_lstclear_ps(t_list_ps **lst, void (*del)(int *))
{
	t_list_ps	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_ps(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

static void	new_stack(t_stack *stack)
{
	stack->list = NULL;
	stack->size = 0;
	stack->nb_instruction = 0;
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack_a;
	t_stack		stack_b;
	t_list_ps	*new_node;

	if (argc < 2)
		return ((void)write(2, "Error\n", 6), 1);
	i = 1;
	new_stack(&stack_a);
	new_stack(&stack_b);
	stack_a.list = ft_lstnew_ps(ft_atoi(argv[i++]));
	if (!stack_a.list)
		return ((void)write(2, "Error\n", 6), 1);
	while (i < argc)
	{
		new_node = ft_lstnew_ps(ft_atoi(argv[i++]));
		if (!new_node)
		{
			ft_lstclear_ps(&stack_a.list, &del);
			return ((void)write(2, "Error\n", 6), 1);
		}
		ft_lstadd_back_ps(&stack_a.list, new_node);
		stack_a.size++;
	}
	printf("-------------------------------------------------------------------\n");
	print_list(stack_a, stack_b);

	sort(&stack_a, &stack_b);

	printf("-------------------------------------------------------------------\n");
	print_list(stack_a, stack_b);
	printf("nb instruction : %lu\n", stack_a.nb_instruction + stack_b.nb_instruction);
	ft_lstclear_ps(&stack_a.list, &del);
	ft_lstclear_ps(&stack_b.list, &del);
	return (0);
}
