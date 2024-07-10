/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:16:26 by dsatge            #+#    #+#             */
/*   Updated: 2024/04/25 17:45:02 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"

typedef struct s_swap
{
	char			**tab;
}			t_swap;

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}			t_node;

/// TEST 
void	ft_print_stack(t_node **stack);
/// CREATE_LINE
char	**line_conf(int argc, char **argv);
int		error_line_config(t_swap *swap);
/// ERROR_ARGUMENT
int		error_sign_num(t_swap *swap);
int		error_double(t_swap *swap);
int		error_empty_arg(int argc, char **argv);
int		error_out_limits(t_swap *swap);
int		error_len_num(t_swap *swap);
/// UTILS
int		wr_err(char *str, t_swap *swap);
int		wr_err_list(char *str, t_node *element, char **line_conf);
void	*ft_free(char **strs, int count);
void	ft_free_list(t_node *element);
/// LIST_SET_UP
t_node	*list_from_tab(char **line_conf);
/// RULES
t_node	*ab_swap(t_node *stack);
t_node	*a_push(t_node **stack_a, t_node **stack_b);
t_node	*b_push(t_node **stack_a, t_node **stack_b);
t_node	*ab_rotate(t_node **stack);
t_node	*ab_reverse(t_node **stack);
// RULES_COMMAND
t_node	*command_action(t_node **stack_a, t_node **stack_b, char *ope);
// SORTING
int		ft_median(t_node **stack);
t_node	*fill_stack_b(t_node **stack_a, t_node **stack_b);
t_node	*two_element_order(t_node **stack_a, t_node **stack_b);
t_node	*three_element_order(t_node **stack_a, t_node **stack_b);
t_node	*sort_three(t_node **stack);
//SORT_COMMAND
t_node	*sort_command(t_node **stack_a, t_node **stack_b);
t_node	*execute_sort(t_node **stack_a, t_node **stack_b);
t_node	*bring_final(t_node **stack_a, t_node **stack_b);
int		move_top_target(int target, t_node **stack);
int		move_top_cheap(int cheapest, t_node **stack);
// UTILS_SORT
int		count_data(t_node **stack);
int		node_position(t_node **stack, int node);
int		diff_num(int start, int end);
int		find_smallest(t_node **stack);
int		find_biggest(t_node **stack);
//MOVE_TO_B
t_node	*move_to_b(t_node **stack_a, t_node **stack_b);
int		*ordered_list(t_node **stack);
int		*fill_tab(t_node **stack, int len, int *tab);
int		*ft_sort(int len, int *tab);
int		median_math(t_node **stack);
//MOVE_TO_A
int		move_set_return(int target, int element,
			t_node **stack_a, t_node **stack_b);
int		target_node_to_a(t_node **stack, int node);
int		find_cheap_ret(t_node **stack_a, t_node **stack_b);
int		move_target_top(int target, t_node **stack_a);
int		move_cheap_top(int cheapest, t_node **stack_b);
//SMART_MOVE.c
t_node	*move_ups(int target, int cheap, t_node **stack_a, t_node **stack_b);
void	move_two_under(int move_a, int move_b, t_node **stack_a,
			t_node **stack_b);
void	move_two_above(int move_a, int move_b, t_node **stack_a,
			t_node **stack_b);
void	move_two_random(int move_a, int move_b, t_node **stack_a,
			t_node **stack_b);
//EXTRA.C
void	ft_swap(int *i, int *j);
int		check_init(t_node **stack_a);
int		check_identical(int len, int *tab_start, int *tab_sort);
int		is_smallest(int i, int j);
#endif
