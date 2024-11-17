#include "push_swap.h"

static void	free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

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

static int	check_duplicate(t_stack *stack, int nb)
{
	t_list_ps	*cp;

	cp = stack->list;
	while (cp)
	{
		if (cp->nb == nb)
			return (-1);
		cp = cp->next;
	}
	return (0);
}

int	parse_number_split(char **argv_split, t_stack *stack)
{
	t_list_ps	*new_node;
	int			nb;
	size_t		i;

	i = 0;
	while (argv_split[i])
	{
		nb = ft_atoi_safe(argv_split[i]);
		if (check_duplicate(stack, nb) != 0)
			return (ft_lstclear_ps(&stack->list, NULL), \
			free_split(argv_split), -1);
		if (nb == 0 && ft_strncmp(argv_split[i], "0", 1))
			return (-1);
		new_node = ft_lstnew_ps(nb);
		if (!new_node)
			return (ft_lstclear_ps(&stack->list, NULL), \
			free_split(argv_split), -1);
		ft_lstadd_back_ps(&stack->list, new_node);
		stack->size += 1;
		i++;
	}
	free_split(argv_split);
	return (0);
}

int	parse_number_n(char **argv, int argc, t_stack *stack)
{
	t_list_ps	*new_node;
	int			nb;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (check_string(argv[i]) != 0)
			return (ft_lstclear_ps(&stack->list, NULL), -1);
		nb = ft_atoi_safe(argv[i]);
		if (check_duplicate(stack, nb) != 0)
			return (ft_lstclear_ps(&stack->list, NULL), -1);
		if (nb == -69 && ft_strncmp(argv[i], "-69", ft_strlen(argv[i])))
			return (ft_lstclear_ps(&stack->list, NULL), -1);
		new_node = ft_lstnew_ps(nb);
		if (!new_node)
			return (ft_lstclear_ps(&stack->list, NULL), -1);
		ft_lstadd_back_ps(&stack->list, new_node);
		stack->size += 1;
		i++;
	}
	return (0);
}
