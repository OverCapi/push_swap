/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:29:00 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define ERROR_MSG "Error\n"
# define ERROR_MSG_LEN 6

typedef struct s_stack_node
{
	int					nb;
	int					push_cost;
	int					index;
	int					median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}						t_stack_node;

/* LST FUNCTION */
t_stack_node	*ft_newstack(int nb);
t_stack_node	*ft_stacklast(t_stack_node *stack);
void			ft_stackadd_back(t_stack_node **stack, t_stack_node *new);
void			ft_clearstack(t_stack_node **stack);
void			ft_stackadd_front(t_stack_node **stack, t_stack_node *new);

/* INSTRUCTION */
void			swap(t_stack_node **stack, char c);
void			push(t_stack_node **stack_1, t_stack_node **stack_2, char c);
void			rotate(t_stack_node **stack, char c);
void			reverse_rotate(t_stack_node **stack, char c);
void			rotate_double(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate_double(t_stack_node **A, t_stack_node **B);

/* INSTRUCTION DOUBLE */
void			rotate_double(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate_double(t_stack_node **A, t_stack_node **B);

/* PARSING */
int				parse_number_n(char **argv, int argc, t_stack_node **stack);

/* SORT ALGO UTILS */
int				is_sorted(t_stack_node *A);
int				get_size(t_stack_node *stack);
void			sort_three(t_stack_node **A);
t_stack_node	*get_min_node(t_stack_node *stack);
t_stack_node	*get_max_node(t_stack_node *stack);

/* TARGET NODE */
t_stack_node	*get_closest_big(t_stack_node *A, t_stack_node *node);
void			update_target_node(t_stack_node **A, t_stack_node *B);

/* COST PUSH */
void			update_cost_push(t_stack_node **A, t_stack_node *B);
t_stack_node	*get_cheapest_node(t_stack_node *stack);

/* UPDATE */
void			update(t_stack_node **A, t_stack_node **B, int index);

/* SORT ALGO */
void			sort(t_stack_node **stack_a, t_stack_node **stack_b);

#endif