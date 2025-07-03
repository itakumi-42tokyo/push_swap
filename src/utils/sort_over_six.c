/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 15:49:53 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>
// 連番であるといいこと。　中央値を取りやすい。

void	carry_out_cost(t_cost *cost, t_root *stack_a, t_root *stack_b)
{
	while ((cost->ra)--)
		ra(stack_a);
	while ((cost->rb)--)
		rb(stack_b);
	while ((cost->rr)--)
		rr(stack_a, stack_b);
	while ((cost->rra)--)
		rra(stack_a);
	while ((cost->rrb)--)
		rrb(stack_b);
	while ((cost->rrr)--)
		rrr(stack_a, stack_b);
}

// ノードを消すということは、その分初期化をしなければいけない。
t_singl	*sort_over_six(int argc, t_root *stack_a)
{
	int		i;
	int		count;
	int		index;
	t_list	*cur;
	t_cost	*cost;
	t_root	*stack_b;

	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	find_lis(argc, stack_a);
	cur = stack_a->sentinel->next;
	// コスト計算をして、pbする
	i = 0;
	// 非LISがなくなるまで、pbする。
	count = stack_a->node_len - stack_a->lis_count;
	while (i++ < count)
	{
		if (check_sorted_s(stack_a))
			break;
		cost = count_cost_pb(stack_a, stack_b);
		carry_out_cost(cost, stack_a, stack_b);
		free(cost);
	}
	i = 0;
	while (i++ < stack_b->node_len)
	{
		cost = count_cost(stack_a, stack_b);
		carry_out_cost(cost, stack_a, stack_b);
		free(cost);
	}
	// topに戻してあげる。
	// どちらのローテーションが早いか確認する。
	index = get_target_index(stack_a, 0);
	if (index < (stack_a->node_len) / 2)
	{
		while (stack_a->sentinel->next->number != 0)
			ra(stack_a);
	}
	else
	{
		while (stack_a->sentinel->next->number != 0)
			rra(stack_a);
	}
	return (0);
}
