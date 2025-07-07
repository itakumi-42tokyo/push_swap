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
// 連番であるといいこと。　中央値を取りやすい。

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

// ノードを消すということは、その分初期化をしなければいけない。
// lisが３つより少なければ、しょうがないので、３つでソートする道を選ぶ仕様にしよう。
t_singl	*sort_over_six(int argc, t_root *stack_a)
{
	int		i;
	int		count;
	int		index;
	int		stack_b_len;
	t_cost	*cost;
	t_root	*stack_b;

	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	find_lis(argc, stack_a);
	// LIS がデータサイズに対して十分でない場合は fallback
	if (stack_a->lis_count < stack_a->node_len / 6)
	{
		cdll_clear(&stack_b, cdll_delone);
		return (sort_best_move(argc, stack_a));
	}
	// コスト計算をして、pbする
	i = 0;
	// 非LISがなくなるまで、pbする。
	count = stack_a->node_len - stack_a->lis_count;
	// printf("node_len: %d\n", stack_a->node_len);
	// printf("lis_count: %d\n", stack_a->lis_count);
	while (i++ < count)
	{
		if (check_sorted_s(stack_a))// ローテーションしてしまうので、イマイチチェックする必要がない。
			break;
		cost = count_cost_pb(stack_a, stack_b, true);
		carry_out_cost(cost, stack_a, stack_b);
		pb(stack_a, stack_b);
		free(cost);
	}
	i = 0;
	stack_b_len = stack_b->node_len;
	while (i++ < stack_b_len)
	{
		cost = count_cost_pa(stack_a, stack_b);// どれを動かしているかはわからないが、最小のコストの操作が帰る。
		carry_out_cost(cost, stack_a, stack_b);
		pa(stack_a, stack_b);
		free(cost);
	}
	// stack_bは降順どちらにしたほうが良いのか？降順
	// 理由はローテーションする必要がなくなるから。
	// topに戻してあげる。
	// どちらのローテーションが早いか確認する。
	index = get_target_index(stack_a, 0);
	if (index <= (stack_a->node_len) / 2)
	{
		while (stack_a->sentinel->next->number != 0)
			ra(stack_a);
	}
	else
	{
		while (stack_a->sentinel->next->number != 0)
			rra(stack_a);
	}
	cdll_clear(&stack_b, cdll_delone);
	return (NULL);
}
