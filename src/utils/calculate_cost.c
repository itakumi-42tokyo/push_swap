/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:05:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/04 13:55:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"
#include <math.h>

// 構造体にlisかどうかを判別するフラグを追加したほうがいいのでは

// 無限大を作るのは面倒なので、同じ数字が入っていないという性質を使用する？
// そもそも正規化しているのでマイナスが入らない。

void	init_min_cost(t_cost **min_cost)
{
	(*min_cost)->ra = INT_MAX;
	(*min_cost)->rb = INT_MAX;
	(*min_cost)->rr = INT_MAX;
	(*min_cost)->rra = INT_MAX;
	(*min_cost)->rrb = INT_MAX;
	(*min_cost)->rrr = INT_MAX;
}

void	init_cost(t_cost **cost)
{
	(*cost)->ra = 0;
	(*cost)->rb = 0;
	(*cost)->rr = 0;
	(*cost)->rra = 0;
	(*cost)->rrb = 0;
	(*cost)->rrr = 0;
}

// 現在の状況下で、どの要素が一番コストが低いかを確認する関数。
// なぜ、s系を使わないかというとソートされた形を崩したくないから。
// 今回はpa専用の関数

int	compere_cost(t_cost *cost1, t_cost *cost2) // 1 -> cost1 is bigger
{
	long long	cost1_sum;
	long long	cost2_sum;

	cost1_sum = 0;
	cost1_sum += cost1->ra;
	cost1_sum += cost1->rb;
	cost1_sum += cost1->rr;
	cost1_sum += cost1->rra;
	cost1_sum += cost1->rrb;
	cost1_sum += cost1->rrr;
	cost2_sum = 0;
	cost2_sum += cost2->ra;
	cost2_sum += cost2->rb;
	cost2_sum += cost2->rr;
	cost2_sum += cost2->rra;
	cost2_sum += cost2->rrb;
	cost2_sum += cost2->rrr;
	if (cost1_sum > cost2_sum)
		return (1);
	else if (cost1_sum < cost2_sum)
		return (-1);
	return (0);
}

// これってダブルポインタの必要あったっけ？
void	minimize_cost(t_cost **cost)
{
	while ((*cost)->ra >= 1 && (*cost)->rb >= 1)
	{
		(*cost)->rr += 1;
		(*cost)->ra -= 1;
		(*cost)->rb -= 1;
	}
	while ((*cost)->rra >= 1 && (*cost)->rrb >= 1)
	{
		(*cost)->rrr += 1;
		(*cost)->rra -= 1;
		(*cost)->rrb -= 1;
	}
}

// 最適なコストの構成要素を返しても、どの順序で挿入したら良いかが分からない。
// と思われるかもしれないが、実際は、ローテーションした最後にpaすればよいだけなので、すぐに分かる。

// lis用と一般的なコスト計算用で分ける必要がある？
// これは、paするためのコスト計算

void	copy_cost(t_cost *cost, t_cost **min_cost)
{
	(*min_cost)->ra = cost->ra;
	(*min_cost)->rb = cost->rb;
	(*min_cost)->rr = cost->rr;
	(*min_cost)->rra = cost->rra;
	(*min_cost)->rrb = cost->rrb;
	(*min_cost)->rrr = cost->rrr;
}

void	count_cost_process(t_root *stack_a, t_cost **min_cost)
{
	int		index;
	t_list	*cur_a;

	cur_a = stack_a->sentinel->next;
	index = 0;
	init_cost(min_cost);
	while (cur_a != stack_a->sentinel)
	{
		if (cur_a->lis == false)
		{
			if (index <= stack_a->node_len / 2)
				(*min_cost)->ra = index;
			else
				(*min_cost)->rra = stack_a->node_len - index;
			break;
		}
		cur_a = cur_a->next;
		index++;
	}
}

// paのコストを計算するとき、Bに一つもないときは、このコスト計算はうまく働くだろうか
t_cost	*count_cost_pa(t_root *stack_a, t_root *stack_b)
{
	int		i;
	int		target;
	int		index;
	t_list	*cur_b;
	t_cost	*cost;
	t_cost	*min_cost;

	if (!stack_a || !stack_a->sentinel || !stack_b || !stack_b->sentinel)
		return (NULL);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return (NULL);
	min_cost = malloc(sizeof(t_cost));
	if (min_cost == NULL)
		return (free(cost), NULL);
	init_min_cost(&min_cost);
	cur_b = stack_b->sentinel->next;
	i = 0;
	// stack_aとstack_bの状態は変化しないということが前提だ。
	// stack_aに対してもやらないといけないのか。これは大丈夫。
	while (cur_b != stack_b->sentinel)
	{
		init_cost(&cost);
		target = get_next_number(cur_b->number, stack_a);
		index = get_target_index(stack_a, target);
		if (index < stack_a->node_len / 2)
			cost->ra = index;
		else
			cost->rra = stack_a->node_len - index;
		if (i <= stack_b->node_len / 2)
			cost->rb = i;
		else
			cost->rrb = stack_b->node_len - i;
		minimize_cost(&cost);
		if (compere_cost(cost, min_cost) == -1)
		{
			copy_cost(cost, &min_cost);
		}
		cur_b = cur_b->next;
		i++;
	}
	return (free(cost), min_cost);
}

#include <stdio.h>
t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f)
{
	int		i;
	int		target;
	int		index;
	t_list	*cur_a;
	t_cost	*cost;
	t_cost	*min_cost;

	if (!stack_a || !stack_a->sentinel || !stack_b || !stack_b->sentinel)
		return (NULL);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return (NULL);
	min_cost = malloc(sizeof(t_cost));
	if (min_cost == NULL)
		return (free(cost), NULL);
	init_min_cost(&min_cost);
	if (stack_b->node_len == 0)// B node_lenが1 or 0のときは、コストが変化しない。
	{// いらない気もする。
		if (lis_f)
			return (free(cost),count_cost_process(stack_a, &min_cost), min_cost);
		return (free(cost), init_cost(&min_cost), min_cost);
	}
	cur_a = stack_a->sentinel->next;
	i = 0;
	while (cur_a != stack_a->sentinel)
	{
		init_cost(&cost);
		if (lis_f && cur_a->lis)// 非LISを探しているので飛ばす。
		{
			cur_a = cur_a->next;
			i++;
			continue;
		}
		target = get_next_number(cur_a->number, stack_b);// ここでpbするのは、ターゲットよりも一つ少ない数字である。
		index = get_target_index(stack_a, target);
		if (index <= stack_b->node_len / 2)
			cost->rb = index;
		else
			cost->rrb = stack_b->node_len - index;
		if (i <= stack_a->node_len / 2)
			cost->ra = i;
		else
			cost->rra = stack_a->node_len - i;
		minimize_cost(&cost);
		if (compere_cost(cost, min_cost) == -1)
			copy_cost(cost, &min_cost);
		cur_a = cur_a->next;
		i++;
	}
	return (free(cost), min_cost);
}
