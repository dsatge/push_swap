/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:55:28 by dsatge            #+#    #+#             */
/*   Updated: 2024/03/27 11:47:21 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"
#include "../push_swap.h"

int	wr_err(char *str, t_swap *swap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	ft_free(swap->tab, ft_count_line_split(swap->tab));
	exit (0);
	return (0);
}

int	wr_err_list(char *str, t_node *element, char **line_conf)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	ft_free_list(element);
	ft_free(line_conf, ft_count_line_split(line_conf));
	exit (0);
	return (0);
}

void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

void	ft_free_list(t_node *element)
{
	t_node	*tmp;

	if (element == NULL)
		exit (0);
	while (element->next != NULL)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	free(element);
}
