/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:37 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/22 17:27:17 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *str)
{
	size_t	i;

	i = 0;
	while (ft_iswhite_space(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (i < ft_strlen(str))
		return (-1);
	return (0);
}

static int	check_duplicate(t_stack_node *stack, int nb)
{
	while (stack)
	{
		if (stack->nb == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	parse_number_n(char **argv, int argc, t_stack_node **stack)
{
	t_stack_node	*new_node;
	int				nb;
	int				i;

	i = 1;
	while (i < argc)
	{
		if (check_string(argv[i]) != 0)
			return (ft_clearstack(stack), -1);
		nb = ft_atoi_safe(argv[i]);
		if (check_duplicate(*stack, nb) != 0)
			return (ft_clearstack(stack), -1);
		if (nb == -69 && ft_strncmp(argv[i], "-69", ft_strlen(argv[i])))
			return (ft_clearstack(stack), -1);
		new_node = ft_newstack(nb);
		if (!new_node)
			return (ft_clearstack(stack), -1);
		ft_stackadd_back(stack, new_node);
		i++;
	}
	return (0);
}
