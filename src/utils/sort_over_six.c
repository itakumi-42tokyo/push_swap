/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/05 18:00:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>

void	carry_out_cost(t_cost *cost, t_root *stack_a, t_root *stack_b)
{
	while ((cost->ra)-- > 0)
		ra(stack_a);
	while ((cost->rb)-- > 0)
		rb(stack_b);
	while ((cost->rr)-- > 0)
		rr(stack_a, stack_b);
	while ((cost->rra)-- > 0)
		rra(stack_a);
	while ((cost->rrb)-- > 0)
		rrb(stack_b);
	while ((cost->rrr)-- > 0)
		rrr(stack_a, stack_b);
}

/*
** Push non-LIS elements from stack A to stack B
** Uses cost calculation to find optimal element to push
*/
static void	push_non_lis_to_b(t_root *stack_a, t_root *stack_b)
{
	int		i;
	int		count;
	t_cost	*cost;

	i = 0;
	count = stack_a->node_len - stack_a->lis_count;
	while (i < count)
	{
		cost = count_cost_pb(stack_a, stack_b, true);
		carry_out_cost(cost, stack_a, stack_b);
		pb(stack_a, stack_b);
		free(cost);
		i++;
	}
}

/*
** Merge elements back from stack B to stack A
** Uses cost calculation to find optimal position for each element
*/
static void	merge_b_to_a(t_root *stack_a, t_root *stack_b)
{
	int		i;
	int		len;
	t_cost	*cost;

	i = 0;
	len = stack_b->node_len;
	while (i < len)
	{
		cost = count_cost_pa(stack_a, stack_b);
		carry_out_cost(cost, stack_a, stack_b);
		pa(stack_a, stack_b);
		free(cost);
		i++;
	}
}

/*
** Rotate stack A to put the minimum value (0) at the top
** Chooses optimal rotation direction based on position
*/
static void	rotate_min_to_top(t_root *stack_a)
{
	int	index;

	index = get_target_index(stack_a, 0);
	if (index <= stack_a->node_len / 2)
		while (stack_a->sentinel->next->number != 0)
			ra(stack_a);
	else
		while (stack_a->sentinel->next->number != 0)
			rra(stack_a);
}

/*
** Main sorting function for 6+ elements
** Uses LIS (Longest Increasing Subsequence) optimization
** Falls back to best_move algorithm if LIS is too small
*/
t_singl	*sort_over_six(int argc, t_root *stack_a)
{
	(void)argc;
	t_root	*stack_b;

	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	find_lis(argc, stack_a);
	if (stack_a->lis_count < stack_a->node_len / 6)
	{
		cdll_clear(&stack_b, cdll_delone);
		return (sort_best_move(argc, stack_a));
	}
	push_non_lis_to_b(stack_a, stack_b);
	merge_b_to_a(stack_a, stack_b);
	rotate_min_to_top(stack_a);
	cdll_clear(&stack_b, cdll_delone);
	return (NULL);
}
