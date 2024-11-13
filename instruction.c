/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:50:49 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 12:28:40 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
Intervertit les 2 premiers éléments au sommet de la pile.
Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap(t_stack *stack)
{
	void	*ctn_tmp;

	if (stack->size < 2)
		return ;
	ctn_tmp = stack->list->content;
	stack->list->content = stack->list->next->content;
	stack->list->next->content = ctn_tmp;
}

/*
Prend le premier élément au sommet de 1 et le met sur 2.
Ne fait rien si 1 est vide.
*/
void	push(t_stack *stack_1, t_stack *stack_2)
{
	if (stack_1->size == 0)
		return ;
	if (!stack_2->list)
	{
		stack_2->list = stack_1->list;
		stack_2->list->next = NULL;
	}
	else
		ft_lstadd_front(&stack_2->list, stack_1->list);
	stack_1->list = stack_1->list->next;
	stack_1->size += 1;
	stack_2->size -= 1;
}

/*
Décale d’une position vers le haut tous les élements de la pile.
Le premier élément devient le dernier.
*/
void	rotate(t_stack *stack)
{
	t_list	*tmp_list;

	if (stack->size < 2)
		return ;
	tmp_list = stack->list->next;
	ft_lstadd_back(&tmp_list, stack->list);
	stack->list->next = NULL;
	stack->list = tmp_list;
}

/*
Décale d’une position vers le bas tous les élements de
la pile. Le dernier élément devient le premier.
*/
void	reverse_rotate(t_stack *stack)
{
	t_list	*last_node;
	t_list	*second_last_node;

	if (stack->size < 2)
		return ;
	last_node = ft_lstlast(stack->list);
	second_last_node = stack->list;
	while (second_last_node->next->next)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = stack->list;
	stack->list = last_node;
}
