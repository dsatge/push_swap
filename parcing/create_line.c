/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:54:09 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/23 17:29:16 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/printf/ft_printf.h"
#include "../push_swap.h"

static int	arg_size(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = 1;
	j = 0;
	size = 0;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
		{
			size++;
			k++;
		}
		size++;
		i++;
	}
	return (size);
}

static char	*arg_line(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 1;
	j = 0;
	str = malloc(sizeof(char) * (arg_size(argc, argv) + 1));
	if (!str)
		return (NULL);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
			str[j++] = argv[i][k++];
		str[j++] = ' ';
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	error_line_config(t_swap *swap)
{
	if (error_sign_num(swap) == 1)
		wr_err("Error\n", swap);
	if (error_double(swap) == 1)
		wr_err("Error\n", swap);
	if (error_out_limits(swap) == 1)
		wr_err("Error\n", swap);
	return (0);
}

char	**line_conf(int argc, char **argv)
{
	char	*line;
	char	**tab;

	if (error_empty_arg(argc, argv) == 2)
		exit(0);
	if (error_empty_arg(argc, argv) == 1)
	{
		write(2, "Error\n", 7);
		exit (0);
	}
	line = arg_line(argc, argv);
	tab = ft_split(line, ' ');
	free(line);
	return (tab);
}
