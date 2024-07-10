/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:23 by dsatge            #+#    #+#             */
/*   Updated: 2024/03/27 11:48:12 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"
#include "../push_swap.h"

int	error_sign_num(t_swap *swap)
{
	int	i;
	int	j;

	i = 0;
	while (swap->tab[i])
	{
		if (!swap)
			return (1);
		j = 0;
		if ((swap->tab[i][0] == '-' || swap->tab[i][0] == '+')
				&& swap->tab[i][1] == '\0')
			return (1);
		if ((swap->tab[i][0] == '-' || swap->tab[i][0] == '+'))
			j++;
		while (swap->tab[i][j])
		{
			if (!(swap->tab[i][j] >= '0' && swap->tab[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_double(t_swap *swap)
{
	int	i;
	int	j;

	i = 0;
	while (swap->tab[i] != 0)
	{
		if (!swap)
			return (1);
		j = 1 + i;
		while (swap->tab[j] != NULL)
		{
			if (ft_atoi(swap->tab[i]) == ft_atoi(swap->tab[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error_empty_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	count;

	i = 1;
	if (argc == 1)
		return (2);
	while (i < argc)
	{
		j = 0;
		count = 0;
		len = ft_strlen(argv[i]);
		while (argv[i][j])
		{
			if (argv[i][j] == 32)
				count++;
			j++;
		}
		if (count == len)
			return (1);
		i++;
	}
	return (0);
}

int	error_out_limits(t_swap *swap)
{
	int		i;
	long	conv;

	i = 0;
	while (swap->tab[i])
	{
		if (error_len_num(swap) == 1)
			return (1);
		conv = ft_atol(swap->tab[i]);
		if (!(conv >= -2147483648 && conv <= 2147483647))
			return (1);
		i++;
	}
	return (0);
}

int	error_len_num(t_swap *swap)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (swap->tab[i])
	{
		j = 0;
		len = 0;
		while (swap->tab[i][j] == '0' || swap->tab[i][j] == '-'
				|| swap->tab[i][j] == '+')
				j++;
		while (swap->tab[i][j])
		{
			if (len > 9)
				return (1);
			len++;
			j++;
		}
		i++;
	}
	return (0);
}
