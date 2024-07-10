/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:10:18 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/18 15:41:30 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	move_set_return(int target, int element, t_node **stack_a, t_node **stack_b)
{
	int	move;
	int	move_a;
	int	move_b;
	int	smallest;

	move_a = move_top_cheap(element, stack_b);
	move_b = move_top_target(target, stack_a);
	smallest = is_smallest(move_a, move_b);
	if (move_a < 0 && move_b < 0)
		move = move_a + move_b - smallest;
	else if (move_a >= 0 && move_b >= 0)
	{
		move = move_a + move_b - smallest;
	}
	else
		move = move_a + move_b;
	return (move);
}

int	target_node_to_a(t_node **stack, int node)
{
	t_node	*current;
	int		target;
	int		diff;

	current = *stack;
	target = current->val;
	diff = find_biggest(stack);
	if (node > diff)
	{
		return (find_smallest(stack));
	}
	while (current)
	{
		if (node < current->val)
		{
			if (diff > diff_num(node, current->val))
			{
				target = current->val;
				diff = diff_num(node, target);
			}
		}
		current = current->next;
	}
	return (target);
}

int	find_cheap_ret(t_node **stack_a, t_node **stack_b)
{
	int		cheapest_val;
	int		cheapest_price;
	int		price_node;
	t_node	*element_b;

	element_b = *stack_b;
	price_node = move_set_return(target_node_to_a(stack_a,
				element_b->val), element_b->val, stack_a, stack_b);
	cheapest_val = element_b->val;
	cheapest_price = price_node;
	while (element_b != NULL)
	{
		price_node = move_set_return(target_node_to_a(stack_a,
					element_b->val), element_b->val, stack_a, stack_b);
		if (price_node < cheapest_price)
		{
			cheapest_price = price_node;
			cheapest_val = element_b->val;
		}
		element_b = element_b->next;
	}
	return (cheapest_val);
}

int	move_target_top(int target, t_node **stack_a)
{
	int	median;		
	int	position;
	int	up_a;
	int	sign;

	median = ft_median(stack_a);
	position = node_position(stack_a, target);
	up_a = 0;
	sign = -1;
	if (position == 1)
		return (0);
	if (position <= median)
	{
		sign = 1;
		position = position - 1;
	}
	else
		position = (count_data(stack_a) - position + 1);
	while (position >= 1)
	{
		up_a++;
		position--;
	}
	return (up_a * sign);
}

int	move_cheap_top(int cheapest, t_node **stack_b)
{
	int	median;
	int	position;
	int	loop;
	int	up_b;
	int	sign;

	position = node_position(stack_b, cheapest);
	median = ft_median(stack_b);
	up_b = 0;
	sign = -1;
	if (position == 1)
		return (0);
	if (position <= median)
	{
		sign = 1;
		loop = position - 1;
	}
	else
		loop = (count_data(stack_b) - position + 1);
	while (loop >= 1)
	{
		up_b++;
		loop--;
	}
	return (up_b * sign);
}
