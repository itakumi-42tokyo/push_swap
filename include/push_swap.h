/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:53:30 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 06:26:50 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
// read, write

# include <stdlib.h>
// malloc, free, exit

# include <stdbool.h>
// bool
# include "list.h"
// struct

void	sa(t_root *stack_a);
void	sb(t_root *stack_b);
void	ss(t_root *stack_a, t_root *stack_b);
int		pa(t_root *stack_a, t_root *stack_b);
int		pb(t_root *stack_a, t_root *stack_b);
void	ra(t_root *stack_a);
void	rb(t_root *stack_b);
void	rr(t_root *stack_a, t_root *stack_b);
void	rra(t_root *stack_a);
void	rrb(t_root *stack_b);
void	rrr(t_root *stack_a, t_root *stack_b);
t_root	*coordinate_compression(int *numbers, int *sorted_numbers, int len);
void	quick_sort(int array[], int low, int high);
int		binary_search(int numbers[], int target, int len);
int		*check_error(int argc, char *argv[]);
int		check_duplication(int *numbers, int low, int high);
void	exit_and_errormsg(void);
t_singl	*sort_under_five(int argc, t_root *stack_a);
t_singl	*sort_over_six(t_root *stack_a);
int		ut_top_node_ismin(t_root *linked_list);
int		ut_top_node_ismax(t_root *linked_list);
int		ut_top_node_ismid(t_root *linked_list);
int		ut_tail_node_ismax(t_root *linked_list);
int		ut_tail_node_ismin(t_root *linked_list);
int		ut_tail_node_ismid(t_root *linked_list);
int		*ut_atoi_numbers(int argc, char *argv[]);
int		ut_atoi_with_error(const char *nptr, bool *error);
int		ut_issign(int c);
int		ut_isspace(int c);
char	**ut_produce_double_p(const char *s1, const char *s2);
int		ut_top_node_ismin(t_root *linked_list);
void	print_node(t_singl	*singl);
int		get_max(t_root *linked_list);
int		get_min(t_root *linked_list);
void	put_min_top(t_root *stack_a);

#endif
