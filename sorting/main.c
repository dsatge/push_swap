/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:20 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 18:20:58 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"

void	ft_print_stack(t_node **stack)
{
	t_node	*element;

	element = *stack;
	while (element != NULL)
	{
		ft_printf("%d ", element->val);
		element = element->next;
	}
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	t_node	*stack_a;
	t_node	*stack_b;

	swap.tab = line_conf(argc, argv);
	error_line_config(&swap);
	stack_a = list_from_tab(swap.tab);
	stack_b = NULL;
	if (check_init(&stack_a) == 0)
	{
		ft_free_list(stack_a);
		ft_free_list(stack_b);
		return (0);
	}
	if (count_data(&stack_a) <= 3)
		sort_command(&stack_a, &stack_b);
	else
		execute_sort(&stack_a, &stack_b);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	printf("GOOD");
	return (0);
}
