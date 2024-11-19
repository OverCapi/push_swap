/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:50:49 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/19 19:07:04 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Intervertit les 2 premiers éléments au sommet de la pile.
Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap(t_stack_node **stack)
{
	int	ctn_tmp;

	if (get_size(*stack) < 2)
		return ;
	ctn_tmp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = ctn_tmp;
}

/*
Prend le premier élément au sommet de 1 et le met sur 2.
Ne fait rien si 1 est vide.
*/
void	push(t_stack_node **stack_1, t_stack_node **stack_2)
{
	t_stack_node	*tmp;

	if (get_size(*stack_1) == 0)
		return ;
	tmp = (*stack_1)->next;
	if (!stack_2)
	{
		*stack_2 = *stack_1;
		(*stack_2)->next = NULL;
	}
	else
		ft_stackadd_front(stack_2, *stack_1);
	*stack_1 = tmp;
}

/*
Décale d’une position vers le haut tous les élements de la pile.
Le premier élément devient le dernier.
*/
void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (get_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	ft_stackadd_front(&tmp, *stack);
	(*stack)->next = NULL;
	(*stack) = tmp;
}

/*
Décale d’une position vers le bas tous les élements de
la pile. Le dernier élément devient le premier.
*/
void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*second_last_node;

	if (get_size(*stack) < 2)
		return ;
	last_node = ft_stacklast(*stack);
	second_last_node = *stack;
	while (second_last_node->next->next)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}
