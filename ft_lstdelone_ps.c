/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:32:48 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/17 06:06:43 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone_ps(t_list_ps *lst, void (*del)(int *))
{
	if (!lst)
		return ;
	if (del)
		del(&lst->nb);
	free(lst);
}
