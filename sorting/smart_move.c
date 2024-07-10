/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:45:11 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/26 18:45:15 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*move_ups(int target, int cheap, t_node **stack_a, t_node **stack_b)
{
	int	move_a;
	int	move_b;
	int	smallest;
	int	doubl;

	move_a = move_target_top(target, stack_a);
	move_b = move_cheap_top(cheap, stack_b);
	smallest = is_smallest(move_a, move_b);
	doubl = 0;
	if (move_a < 0 && move_b < 0)
	{
		move_two_under(move_a, move_b, stack_a, stack_b);
	}
	else if (move_a >= 0 && move_b >= 0)
	{
		move_two_above(move_a, move_b, stack_a, stack_b);
	}
	else
	{
		move_two_random(move_a, move_b, stack_a, stack_b);
	}
	return (*stack_a);
}

void	move_two_under(int move_a, int move_b, t_node **stack_a,
		t_node **stack_b)
{
	int	smallest;
	int	doubl;

	move_a = (-move_a);
	move_b = (-move_b);
	smallest = is_smallest(move_a, move_b);
	move_a = move_a - smallest;
	move_b = move_b - smallest;
	doubl = smallest;
	while (doubl-- > 0)
		command_action(stack_a, stack_b, "rrr");
	while (move_a-- > 0)
		command_action(stack_a, stack_b, "rra");
	while (move_b-- > 0)
		command_action(stack_a, stack_b, "rrb");
}

void	move_two_above(int move_a, int move_b, t_node **stack_a,
		t_node **stack_b)
{
	int	doubl;

	doubl = is_smallest(move_a, move_b);
	move_a = move_a - doubl;
	move_b = move_b - doubl;
	while (doubl-- > 0)
		command_action(stack_a, stack_b, "rr");
	while (move_a-- > 0)
		command_action(stack_a, stack_b, "ra");
	while (move_b-- > 0)
		command_action(stack_a, stack_b, "rb");
}

void	move_two_random(int move_a, int move_b, t_node **stack_a,
		t_node **stack_b)
{
	if (move_a < 0)
	{
		move_a = -(move_a);
		while (move_a-- > 0)
			command_action(stack_a, stack_b, "rra");
	}
	if (move_b < 0)
	{
		move_b = -(move_b);
		while (move_b-- > 0)
			command_action(stack_a, stack_b, "rrb");
	}
	while (move_a-- > 0)
		command_action(stack_a, stack_b, "ra");
	while (move_b-- > 0)
		command_action(stack_a, stack_b, "rb");
}
