/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:20:56 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 17:22:32 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*sort_command(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*head;

	head = *stack_a;
	i = count_data(&head);
	if (i == 1)
		return (*stack_a);
	else if (i == 2)
		two_element_order(stack_a, stack_b);
	else if (i == 3)
		three_element_order(stack_a, stack_b);
	else if (i > 3)
	{
		fill_stack_b(stack_a, stack_b);
	}
	head = *stack_a;
	i = count_data(&head);
	if (i == 2)
		two_element_order(stack_a, stack_b);
	else if (i == 3)
		three_element_order(stack_a, stack_b);
	return (*stack_a);
}

t_node	*execute_sort(t_node **stack_a, t_node **stack_b)
{
	int		data;
	int		target;
	int		cheap;

	data = count_data(stack_a);
	sort_command(stack_a, stack_b);
	while (data > 5)
	{
		move_to_b(stack_a, stack_b);
		data--;
	}
	three_element_order(stack_a, stack_b);
	data = count_data(stack_b);
	while (data > 0)
	{
		cheap = find_cheap_ret(stack_a, stack_b);
		target = target_node_to_a(stack_a, cheap);
		move_ups(target, cheap, stack_a, stack_b);
		command_action(stack_a, stack_b, "pa");
		data--;
	}
	bring_final(stack_a, stack_b);
	return (*stack_a);
}

t_node	*bring_final(t_node **stack_a, t_node **stack_b)
{
	int	smallest;
	int	median;

	smallest = find_smallest(stack_a);
	median = ft_median(stack_a);
	while (node_position(stack_a, smallest) != 1)
	{
		if (node_position(stack_a, smallest) > median)
			command_action(stack_a, stack_b, "rra");
		else
			command_action(stack_a, stack_b, "ra");
	}
	return (*stack_a);
}

int	move_top_target(int target, t_node **stack)
{
	int		move;
	int		median;
	int		position;
	t_node	*current;

	move = 0;
	median = ft_median(stack);
	current = *stack;
	if (target == current->val)
		return (0);
	if (target == current->next->val)
		return (1);
	position = node_position(&current, target);
	if (position <= median)
		move = position - 1;
	else
		move = (count_data(stack) - position) + 1;
	return (move);
}

int	move_top_cheap(int cheapest, t_node **stack)
{
	int		move;
	int		median;
	int		position;
	t_node	*current;

	move = 0;
	median = ft_median(stack);
	current = *stack;
	if (cheapest == current->val)
		return (0);
	if (cheapest == current->next->val)
		return (1);
	position = node_position(&current, cheapest);
	if (position <= median)
		move = position - 1;
	else
		move = (count_data(stack) - position) + 1;
	return (move);
}
