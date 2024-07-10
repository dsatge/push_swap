/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_set_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:47:51 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 17:28:33 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"
#include "../push_swap.h"

static void	new_node(char **line_conf, int i, t_node *element)
{
	element->next = malloc(sizeof(t_node));
	if (element->next == NULL)
		wr_err_list("Error\n", element, line_conf);
	element->next->val = ft_atoi(line_conf[i]);
	element->next->next = NULL;
	return ;
}

t_node	*list_from_tab(char **line_conf)
{
	int		i;
	t_node	*element;
	t_node	*head;

	i = 0;
	element = malloc(sizeof(t_node));
	if (element == NULL)
		wr_err_list("Error\n", element, line_conf);
	element->next = NULL;
	element->val = ft_atoi(line_conf[i]);
	head = element;
	i++;
	while (line_conf[i])
	{
		while (element->next != NULL)
			element = element->next;
		new_node(line_conf, i, element);
		i++;
	}
	ft_free(line_conf, ft_count_line_split(line_conf));
	return (head);
}
