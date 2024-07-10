/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:50:25 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 17:26:37 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_code(char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
		return (1);
	else if (ft_strcmp(operation, "sb") == 0)
		return (2);
	else if (ft_strcmp(operation, "ss") == 0)
		return (3);
	else if (ft_strcmp(operation, "pa") == 0)
		return (4);
	else if (ft_strcmp(operation, "pb") == 0)
		return (5);
	else if (ft_strcmp(operation, "rr") == 0)
		return (6);
	else if (ft_strcmp(operation, "rrr") == 0)
		return (7);
	else if (ft_strcmp(operation, "ra") == 0)
		return (8);
	else if (ft_strcmp(operation, "rb") == 0)
		return (9);
	else if (ft_strcmp(operation, "rra") == 0)
		return (10);
	else if (ft_strcmp(operation, "rrb") == 0)
		return (11);
	return (0);
}

static t_node	*swap_push(t_node **stack_a, t_node **stack_b, int action_code)
{
	if (action_code == 1)
	{
		ab_swap(*stack_a);
		ft_printf("sa\n");
	}
	else if (action_code == 2)
	{
		ab_swap(*stack_b);
		ft_printf("sb\n");
	}
	else if (action_code == 3)
	{
		ab_swap(*stack_a);
		ab_swap(*stack_b);
		ft_printf("ss\n");
	}
	return (*stack_a);
}

static t_node	*push_reve(t_node **stack_a, t_node **stack_b, int action_code)
{
	if (action_code == 4)
	{
		a_push(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else if (action_code == 5)
	{
		b_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else if (action_code == 6)
	{
		ab_rotate(stack_a);
		ab_rotate(stack_b);
		ft_printf("rr\n");
	}
	else if (action_code == 7)
	{
		ab_reverse(stack_a);
		ab_reverse(stack_b);
		ft_printf("rrr\n");
	}
	return (*stack_a);
}

static t_node	*rotates(t_node	**stack_a, t_node **stack_b, int action_code)
{
	if (action_code == 8)
	{
		ab_rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (action_code == 9)
	{
		ab_rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (action_code == 10)
	{
		ab_reverse(stack_a);
		ft_printf("rra\n");
	}
	else if (action_code == 11)
	{
		ab_reverse(stack_b);
		ft_printf("rrb\n");
	}
	return (*stack_a);
}

t_node	*command_action(t_node **stack_a, t_node **stack_b, char *ope)
{
	int	action_code;

	action_code = check_code(ope);
	if (action_code == 0)
	{
		write(2, "Error\n", 7);
		return (*stack_a);
	}
	else if (action_code >= 1 && action_code <= 3)
		swap_push(stack_a, stack_b, action_code);
	else if (action_code >= 4 && action_code <= 7)
		push_reve(stack_a, stack_b, action_code);
	else if (action_code >= 8 && action_code <= 11)
		rotates(stack_a, stack_b, action_code);
	return (*stack_a);
}
