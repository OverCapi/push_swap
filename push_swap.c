/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/14 18:18:26 by llemmel          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack	stack_a = (t_stack){
		.list = NULL,
		.size = 0,
		.nb_instruction = 0
	};
	t_stack	stack_b = (t_stack){
		.list = NULL,
		.size = 0,
		.nb_instruction = 0
	};
	size_t	i;

	i = 1;
	int	tab[] =  {76,50,47,75,36,96,89,82,90,24,68,49,21,97,78,58,57,69,93,94,5,22,32,59,43,33,48,72,95,17,80,35,1,34,19,84,39,15,65,70,66,4,55,3,46,9,2,74,62,85,98,71,20,7,42,53,61,60,14,16,29,77,83,12,8,6,91,25,18,23,63,41,31,40,73,81,10,44,79,88,99,64,87,13,30,27,38,11,26,56,52,28,100,92,67,54,86,51,45,37};
	stack_a.list=ft_lstnew_ps(tab[0]);
	stack_a.size = 100;
	while (i < stack_a.size)
	{
		ft_lstadd_back_ps(&stack_a.list, ft_lstnew_ps(tab[i]));
		i++;
	}
	printf("-------------------------------------------------------------------\n");
	print_list(stack_a, stack_b);

	sort(&stack_a, &stack_b);

	print_list(stack_a, stack_b);
	printf("number of instruction to sort the list : %zu\n", stack_a.nb_instruction + stack_b.nb_instruction);

	ft_lstclear_ps(&stack_a.list, &del);
	ft_lstclear_ps(&stack_b.list, &del);
	return (0);
}
