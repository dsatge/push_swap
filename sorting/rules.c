/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:50:03 by dsatge            #+#    #+#             */
/*   Updated: 2024/03/27 18:12:40 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ab_swap(t_node *stack)
{
	int	tmp;

	tmp = stack->val;
	if (stack->next == NULL)
		return (stack);
	stack->val = stack->next->val;
	stack->next->val = tmp;
	return (stack);
}

t_node	*a_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_b == NULL)
		return (*stack_a);
	tmp = (*stack_b);
	if ((*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	else
		(*stack_b) = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	return (*stack_b);
}

t_node	*b_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_a == NULL)
		return (*stack_a);
	tmp = (*stack_a);
	if ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	else
		(*stack_a) = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	return (*stack_a);
}

t_node	*ab_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*new_head;

	head = (*stack);
	if (head->next == NULL)
		return (*stack);
	(*stack) = (*stack)->next;
	new_head = (*stack);
	if ((*stack)->next == NULL)
	{
		ab_swap(*stack);
		return (*stack);
	}
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = head;
	new_head->next->next = NULL;
	return (*stack);
}

t_node	*ab_reverse(t_node **stack)
{
	t_node	*list;
	t_node	*new_last;

	list = (*stack);
	if ((*stack)->next == NULL)
		return (*stack);
	while ((*stack)->next->next != NULL)
		(*stack) = (*stack)->next;
	new_last = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->next = list;
	new_last->next = NULL;
	return (*stack);
}
