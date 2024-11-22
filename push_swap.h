/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/21 18:48:04 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define ERROR_MSG "Error\n"
# define ERROR_MSG_LEN 6

// typedef struct s_stack_node
// {
// 	int 				nb;
// 	int 				push_cost;
// 	int					flag;
// 	struct s_stack_node	*target_node;
// 	struct s_stack_node	*next;
// } 						t_stack_node;

typedef struct s_stack_node
{
	int					nb;
	int					push_cost;
	int					index;
	int					median;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
}						t_stack_node;

/* LST FUNCTION */
t_stack_node	*ft_newstack(int nb);
t_stack_node	*ft_stacklast(t_stack_node *stack);
void			ft_stackadd_back(t_stack_node **stack, t_stack_node *new);
void			ft_clearstack(t_stack_node **stack);
void			ft_stackadd_front(t_stack_node **stack, t_stack_node *new);

void	print_lst(t_stack_node *stack);

/* INSTRUCTION */
void			swap(t_stack_node **stack, char c);
void			push(t_stack_node **stack_1, t_stack_node **stack_2, char c);
void			rotate(t_stack_node **stack, char c);
void			reverse_rotate(t_stack_node **stack, char c);
void			rotate_double(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate_double(t_stack_node **A, t_stack_node **B);

/* PARSING */
int				parse_number_n(char **argv, int argc, t_stack_node **stack);

/* SORT ALGO */
int				get_size(t_stack_node *stack);
void			sort(t_stack_node **stack_a, t_stack_node **stack_b);

#endif