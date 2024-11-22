/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:20:14 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:26:10 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_double(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a, '\0');
	rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	reverse_rotate_double(t_stack_node **A, t_stack_node **B)
{
	reverse_rotate(A, '\0');
	reverse_rotate(B, '\0');
	ft_printf("rrr\n");
}
