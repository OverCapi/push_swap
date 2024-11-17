/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:31:30 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/17 06:06:33 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
