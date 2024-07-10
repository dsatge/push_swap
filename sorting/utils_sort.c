/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:52:11 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 17:24:21 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_data(t_node **stack)
{
	int		node_count;
	t_node	*head;

	node_count = 1;
	head = *stack;
	if (!head)
		return (0);
	if (head->next == NULL)
		return (1);
	while (head->next != NULL)
	{
		node_count++;
		head = head->next;
	}
	return (node_count);
}

int	node_position(t_node **stack, int node)
{
	t_node	*current;
	int		position;

	position = 1;
	current = *stack;
	while (current && current->val != node)
	{
		position++;
		current = current->next;
	}
	return (position);
}

int	diff_num(int start, int end)
{
	int	diff;
	int	bigger;
	int	smaller;

	if (start > end)
	{
		bigger = start;
		smaller = end;
	}
	else
	{
		bigger = end;
		smaller = start;
	}
	if (start >= 0 && end >= 0)
		diff = bigger - smaller;
	if (start < 0 && end < 0)
		diff = (smaller * -1) - (bigger * -1);
	if (!((start >= 0 && end >= 0) || (start < 0 && end < 0)))
		diff = (-smaller) + bigger;
	return (diff);
}

int	find_smallest(t_node **stack)
{
	int		smallest;
	t_node	*current;

	current = *stack;
	smallest = current->val;
	while (current)
	{
		if (smallest > current->val)
			smallest = current->val;
		current = current->next;
	}
	return (smallest);
}

int	find_biggest(t_node **stack)
{
	int		biggest;
	t_node	*current;

	current = *stack;
	biggest = current->val;
	while (current)
	{
		if (biggest < current->val)
			biggest = current->val;
		current = current->next;
	}
	return (biggest);
}
