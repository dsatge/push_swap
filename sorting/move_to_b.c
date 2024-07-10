/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:09:59 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/26 12:17:51 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*move_to_b(t_node **stack_a, t_node **stack_b)
{
	int		median;
	t_node	*current;

	median = median_math(stack_b);
	command_action(stack_a, stack_b, "pb");
	current = *stack_b;
	if (current->val > median)
		command_action(stack_a, stack_b, "rb");
	return (*stack_b);
}

int	*ordered_list(t_node **stack)
{
	int		len;
	int		*tab;

	len = count_data(stack);
	tab = malloc(sizeof(int *) * (len + 1));
	if (!tab)
		return (0);
	fill_tab(stack, len, tab);
	tab = ft_sort(len, tab);
	return (tab);
}

int	*ft_sort(int len, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] < tab[i])
			{
				ft_swap(&tab[i], &tab[j]);
				j = i + 1;
			}
			else
				j++;
		}
		i++;
	}
	return (tab);
}

int	*fill_tab(t_node **stack, int len, int *tab)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *stack;
	while (i < len)
	{
		tab[i] = current->val;
		i++;
		current = current->next;
	}
	tab[i] = '\0';
	return (tab);
}

int	median_math(t_node **stack)
{
	int	mid;
	int	len;
	int	median_val;
	int	*tab;

	len = count_data(stack);
	if (len % 2 == 0)
		mid = len / 2;
	else
		mid = len / 2 + 1;
	tab = ordered_list(stack);
	median_val = tab[mid];
	free(tab);
	return (median_val);
}
