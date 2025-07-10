/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:53:30 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:48:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_ARG 500

# include <unistd.h>
// read, write

# include <stdlib.h>
// malloc, free, exit

# include <stdbool.h>
// bool

# include <limits.h>
// INT_MIN, INT_MAX

# include "list.h"
// struct

void	sa(t_root *stack_a);
void	sb(t_root *stack_b);
void	ss(t_root *stack_a, t_root *stack_b);
void	pa(t_root *stack_a, t_root *stack_b);
void	pb(t_root *stack_a, t_root *stack_b);
void	ra(t_root *stack_a);
void	rb(t_root *stack_b);
void	rr(t_root *stack_a, t_root *stack_b);
void	rra(t_root *stack_a);
void	rrb(t_root *stack_b);
void	rrr(t_root *stack_a, t_root *stack_b);
t_root	*coord_comp(int *numbers, int *sorted_numbers, int len);
void	quick_sort(int array[], int low, int high);
int		binary_search(int numbers[], int target, int len);
int		*check_error(int argc, char *argv[]);
int		check_duplication(int *numbers, int low, int high);
void	exit_and_errormsg(void);
void	sort_five(t_root *stack_a, t_root *stack_b);
int		sort_under_five(int argc, t_root *stack_a);
int		sort_over_six(int argc, t_root *stack_a);
int		sort_best_move(t_root *stack_a);
int		*ut_atoi_numbers(int argc, char *argv[]);
int		ut_atoi_with_error(const char *nptr, bool *error);
int		ut_issign(int c);
int		ut_isspace(int c);
char	**ut_produce_double_p(const char *s1, const char *s2);
void	print_node(t_singl	*singl);
int		get_max(t_root *linked_list);
int		get_min(t_root *linked_list);
int		get_prev_number(int now, t_root *linked_list);
int		get_next_number(int limit, t_root *linked_list);
int		get_target_index(t_root *linked_list, int target);
int		fill_numbers_from_list(t_root *linked_list, int *numbers);
int		check_sorted_s(t_root *stack);
void	put_min_top(t_root *stack_a);
int		find_lis(int argc, t_root *stack_a);
int		check_sorted(int *numbers, int len);
int		sort_three(t_root *stack_a);
void	init_min_cost(t_cost **min_cost);
void	init_cost(t_cost **cost);
int		compere_cost(t_cost *cost1, t_cost *cost2);
void	minimize_cost(t_cost **cost);
void	copy_cost(t_cost *cost, t_cost **min_cost);
void	carry_out_cost(t_cost *cost, t_root *stack_a, t_root *stack_b);
t_cost	*count_cost_pa(t_root *stack_a, t_root *stack_b);
t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f);
void	count_cost_process(t_root *stack_a, t_cost **min_cost);
void	update_min_cost(t_cost **min_cost, t_cost *candidate);
void	init_cost_zero(t_cost *cost);
int		total_cost(t_cost *cost);
void	set_cost_for_pb(t_root *a, t_root *b, t_cost *cost, int idx0_num1[]);
void	set_cost_for_pa(t_root *stack_a, t_root *stack_b, t_cost *cost, int i);
void	insert_sorted_pb(t_root *stack_a, t_root *stack_b);
int		*format_array(t_root *root);
int		find_lis(int argc, t_root *stack_a);
int		lis(int arr[], int n, int result[]);

#endif
