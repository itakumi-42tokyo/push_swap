/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/05 18:00:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Push elements to B using cost-based approach
*/
static void	push_to_b_cost_based(t_root *stack_a, t_root *stack_b, int to_push)
{
	int		i;
	t_cost	*cost;

	i = 0;
	while (i < to_push)
	{
		cost = count_cost_pb(stack_a, stack_b, false);
		carry_out_cost(cost, stack_a, stack_b);
		pb(stack_a, stack_b);
		free(cost);
		i++;
	}
}

/*
** Merge elements back from B to A using cost-based approach
*/
static void	merge_from_b_cost_based(t_root *stack_a, t_root *stack_b)
{
	int		i;
	int		stack_b_len;
	t_cost	*cost;

	stack_b_len = stack_b->node_len;
	i = 0;
	while (i < stack_b_len)
	{
		cost = count_cost_pa(stack_a, stack_b);
		carry_out_cost(cost, stack_a, stack_b);
		pa(stack_a, stack_b);
		free(cost);
		i++;
	}
}

/*
** Fallback sorting method using cost-based push/merge
*/
t_singl	*sort_best_move(int argc, t_root *stack_a)
{
	int		to_push;
	int		index;
	t_root	*stack_b;

	(void)argc;
	stack_b = ut_create_root();
	if (!stack_b)
		return (NULL);
	to_push = stack_a->node_len - 3;
	push_to_b_cost_based(stack_a, stack_b, to_push);
	sort_three(stack_a, NULL);
	merge_from_b_cost_based(stack_a, stack_b);
	index = get_target_index(stack_a, get_min(stack_a));
	if (index <= stack_a->node_len / 2)
	{
		while (index-- > 0)
			ra(stack_a);
	}
	else
	{
		index = stack_a->node_len - index;
		while (index-- > 0)
			rra(stack_a);
	}
	cdll_clear(&stack_b, cdll_delone);
	return (NULL);
}
