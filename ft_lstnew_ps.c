/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:24:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/17 06:06:51 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_lstnew_ps(int nb)
{
	t_list_ps	*lst;

	lst = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!lst)
		return (NULL);
	lst->nb = nb;
	lst->next = NULL;
	return (lst);
}
