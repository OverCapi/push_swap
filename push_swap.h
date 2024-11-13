/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:43:03 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>

typedef struct s_stack
{
	t_list	*list;
	size_t	size;
}			t_stack;

/* INSTRUCTION */
void	swap(t_stack *stack);
void	push(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif