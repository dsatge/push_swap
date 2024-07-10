/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:50:39 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/26 12:19:23 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	check_init(t_node **stack_a)
{
	int		*tab_start;
	int		*tab_sorted;
	int		len;

	len = count_data(stack_a);
	tab_start = malloc(sizeof(int *) * (len + 1));
	if (!tab_start)
		return (0);
	tab_sorted = malloc(sizeof(int *) * (len + 1));
	if (!tab_sorted)
		return (free(tab_start), 0);
	tab_start = fill_tab(stack_a, len, tab_start);
	tab_sorted = fill_tab(stack_a, len, tab_sorted);
	tab_sorted = ft_sort(len, tab_sorted);
	if (check_identical(len, tab_start, tab_sorted) == 1)
	{
		free(tab_start);
		free(tab_sorted);
		return (1);
	}
	free(tab_start);
	free(tab_sorted);
	return (0);
}

int	check_identical(int len, int *tab_start, int *tab_sort)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((tab_start[i]) != (tab_sort[i]))
		{
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int	is_smallest(int i, int j)
{
	if (i == 0 || j == 0)
		return (0);
	if (i < j)
		return (i);
	else
		return (j);
}
