/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:27:43 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:27:44 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Fallback algorithm (greedy / best-move)
** 1. 3 要素だけ A に残し残りを B へ送る。
**    – 各 push は count_cost_pb(lis_f=false) で最安コストを選ぶ。
** 2. A の 3 要素を sort_three() で並べる。
** 3. B から A へ、常に最安コストで要素を戻す。
** 4. 最後に最小値をトップへ rotate。
** 既存の cost 計算ユーティリティを再利用するため、
** sort_over_six とロジックがかなり似ているが LIS 判定を使わない。
*/

t_singl *sort_best_move(int argc, t_root *stack_a)
{
	int			to_push;
	int			i;
	int			index;
	t_root		*stack_b;
	t_cost		*cost;

	(void)argc;
	stack_b = ut_create_root();
	if (!stack_b)
		return (NULL);

	/* ---------- Step1 : keep 3 in A, push others to B (cost-based) ---------- */
	to_push = stack_a->node_len - 3;
	i = 0;
	while (i++ < to_push)
	{
		cost = count_cost_pb(stack_a, stack_b, false);
		carry_out_cost(cost, stack_a, stack_b);
		pb(stack_a, stack_b);
		free(cost);
	}

	/* ---------- Step2 : sort remaining three elements ---------- */
	sort_three(stack_a, NULL);

	/* ---------- Step3 : merge back using cost-based pa ---------- */
	while (stack_b->node_len > 0)
	{
		cost = count_cost_pa(stack_a, stack_b);
		carry_out_cost(cost, stack_a, stack_b);
		pa(stack_a, stack_b);
		free(cost);
	}

	/* ---------- Step4 : rotate A so min is on top -------------- */
	index = get_target_index(stack_a, 0);
	if (index <= stack_a->node_len / 2)
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
