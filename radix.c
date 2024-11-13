/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:49:10 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/12 16:32:49 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_max(int tab[], int size, int *max_index)
{
	int	max = tab[0];
	int	i = 0;
	*max_index = 0;
	while (i < size)
	{
		if (max < tab[i])
		{
			max = tab[i];
			*max_index = i;
		}
		i++;
	}
	return (max);
}

int	get_nb_size(int max)
{
	int	size;

	size = 0;
	while (max != 0)
	{
		max /= 10;
		size++;
	}
	return (size);
}

void	radix_sort()
{
	int	tab[] = {5, 7, 3, 4, 1, 9, 0, 2, 8, 6};
	int	max_nb;
	int	max_nb_copy;
	int	max_index;
	int	nb_chiffre;
	int	i;

	max_nb = get_max(tab, 10, &max_index);
	nb_chiffre = get_nb_size(max_nb);
	printf("max : %d, index : %d, nb_chiffre : %d\n", max_nb, max_index, nb_chiffre);
}

int	main(void)
{
	radix_sort();
	return (0);
}