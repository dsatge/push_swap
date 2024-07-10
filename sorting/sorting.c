/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:28:44 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/22 16:52:24 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_median(t_node **stack)
{
	int	stack_len;

	stack_len = count_data(stack);
	if (stack_len % 2 == 0)
		return ((stack_len / 2));
	else
		return ((stack_len / 2) + 1);
}

t_node	*fill_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		element;
	int		element_a;
	t_node	*head_a;

	head_a = (*stack_a);
	element = 0;
	element_a = count_data(&head_a);
	while (element < 2 && element_a > 3)
	{
		element++;
		element_a--;
		command_action(stack_a, stack_b, "pb");
	}
	return (*stack_b);
}

t_node	*two_element_order(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
		command_action(stack_a, stack_b, "sa");
	return (*stack_a);
}

t_node	*three_element_order(t_node **stack_a, t_node **stack_b)
{
	if (((*stack_a)->val > (*stack_a)->next->val)
		&& ((*stack_a)->val > (*stack_a)->next->next->val))
		command_action(stack_a, stack_b, "ra");
	else if (((*stack_a)->val > (*stack_a)->next->val)
		&& ((*stack_a)->next->val > (*stack_a)->next->next->val))
		command_action(stack_a, stack_b, "rra");
	else if (((*stack_a)->val < (*stack_a)->next->val)
		&& ((*stack_a)->next->val > (*stack_a)->next->next->val))
		command_action(stack_a, stack_b, "rra");
	if ((*stack_a)->val > (*stack_a)->next->val)
		command_action(stack_a, stack_b, "sa");
	return (*stack_a);
}
