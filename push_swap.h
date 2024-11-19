/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/19 19:13:47 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define ERROR_MSG "Error\n"
# define ERROR_MSG_LEN 6

typedef struct s_list_ps
{
	int					nb;
	int					index;
	struct s_list_ps	*next;
}						t_list_ps;

typedef struct s_stack
{
	struct s_list_ps	*list;
	size_t				size;
	size_t				nb_instruction;
}						t_stack_nodet_stack;

typedef struct s_stack_node
{
	int 				nb;
	int 				index;
	int 				push_cost;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
} 						t_stack_node;

/* LST FUNCTION */
t_stack_node	*ft_newstack(int nb);
t_stack_node	*ft_stacklast(t_stack_node *stack);
void			ft_stackadd_back(t_stack_node **stack, t_stack_node *new);
void			ft_clearstack(t_stack_node **stack);
void			ft_stackadd_front(t_stack_node **stack, t_stack_node *new);

/* INSTRUCTION */
void			swap(t_stack_node **stack);
void			push(t_stack_node **stack_1, t_stack_node **stack_2);
void			rotate(t_stack_node **stack);
void			reverse_rotate(t_stack_node **stack);

/* PARSING */
int				parse_number_n(char **argv, int argc, t_stack_node **stack);

/* SORT ALGO */
int				get_size(t_stack_node *stack);
void			sort(t_stack_node **stack_a, t_stack_node **stack_b);

#endif