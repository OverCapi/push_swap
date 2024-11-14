/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:50:49 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/14 18:07:16 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
Intervertit les 2 premiers éléments au sommet de la pile.
Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap(t_stack *stack)
{
	int	ctn_tmp;

	if (stack->size < 2)
		return ;
	ctn_tmp = stack->list->nb;
	stack->list->nb = stack->list->next->nb;
	stack->list->next->nb = ctn_tmp;
	stack->nb_instruction += 1;
}

/*
Prend le premier élément au sommet de 1 et le met sur 2.
Ne fait rien si 1 est vide.
*/
void	push(t_stack *stack_1, t_stack *stack_2)
{
	t_list_ps	*tmp;

	if (stack_1->size == 0)
		return ;
	tmp = stack_1->list->next;
	if (!stack_2->list)
	{
		stack_2->list = stack_1->list;
		stack_2->list->next = NULL;
	}
	else
		ft_lstadd_front_ps(&stack_2->list, stack_1->list);
	stack_1->list = tmp;
	stack_1->size -= 1;
	stack_2->size += 1;
	stack_1->nb_instruction += 1;
}

/*
Décale d’une position vers le haut tous les élements de la pile.
Le premier élément devient le dernier.
*/
void	rotate(t_stack *stack)
{
	t_list_ps	*tmp_list;

	if (stack->size < 2)
		return ;
	tmp_list = stack->list->next;
	ft_lstadd_back_ps(&tmp_list, stack->list);
	stack->list->next = NULL;
	stack->list = tmp_list;
	stack->nb_instruction += 1;
}

/*
Décale d’une position vers le bas tous les élements de
la pile. Le dernier élément devient le premier.
*/
void	reverse_rotate(t_stack *stack)
{
	t_list_ps	*last_node;
	t_list_ps	*second_last_node;

	if (stack->size < 2)
		return ;
	last_node = ft_lstlast_ps(stack->list);
	second_last_node = stack->list;
	while (second_last_node->next->next)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = stack->list;
	stack->list = last_node;
	stack->nb_instruction += 1;
}
