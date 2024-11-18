/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:27:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/18 15:21:30 by llemmel          ###   ########.fr       */
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
}						t_stack;

/* LST FUNCTION */
t_list_ps	*ft_lstnew_ps(int nb);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstdelone_ps(t_list_ps *lst, void (*del)(int *));
void		ft_lstclear_ps(t_list_ps **lst, void (*del)(int *));
void		ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);

/* INSTRUCTION */
void		swap(t_stack *stack);
void		push(t_stack *stack_1, t_stack *stack_2);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

/* PARSING */
int			parse_number_n(char **argv, int argc, t_stack *stack);
int			parse_number_split(char **argv_split, t_stack *stack);

/* SORT ALGO */
void		merge_sort(t_stack *stack_a, t_stack *stack_b);

#endif