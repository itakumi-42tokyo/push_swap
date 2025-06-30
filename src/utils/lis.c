/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:05:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/30 21:22:37 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include <math.h>

// 構造体にlisかどうかを判別するフラグを追加したほうがいいのでは
t_root	*lis(t_root *stack)
{

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

int	compere_cost(t_cost *cost1, t_cost *cost2)
{
	int	cost1_sum;
	int	cost2_sum;

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

void	minimize_cost(t_cost **cost)
{
	while ((*cost)->ra < 1 || (*cost)->rb < 1)
	{
		(*cost)->rr += 1;
		(*cost)->ra -= 1;
		(*cost)->rb -= 1;
	}
	while ((*cost)->rra < 1 || (*cost)->rrb < 1)
	{
		(*cost)->rrr += 1;
		(*cost)->rra -= 1;
		(*cost)->rrb -= 1;
	}
	while ((*cost)->ra < 1 || (*cost)->rb < 1)
	{
		(*cost)->rr += 1;
		(*cost)->ra -= 1;
		(*cost)->rb -= 1;
	}
	while ((*cost)->rra < 1 || (*cost)->rrb < 1)
	{
		(*cost)->rrr += 1;
		(*cost)->rra -= 1;
		(*cost)->rrb -= 1;
	}
}

t_cost	*count_cost(t_root *stack_a, t_root *stack_b)
{
	int		i;
	int		target;
	int		index;
	t_list	*cur_b;
	t_cost	*cost;
	t_cost	*min_cost;

	if (!stack_a || !stack_a->sentinel || !stack_b || !stack_b->sentinel)
		return (NULL);
	cost = malloc(sizeof(cost));
	if (cost == NULL)
		return (NULL);
	if (min_cost == NULL)
		return (free(cost), NULL);
	init_cost(&min_cost);
	cur_b = stack_b->sentinel->next;
	while (i < stack_b->node_len)
	{
		init_cost(&cost);
		target = get_next_number(cur_b->number, stack_a);
		index = get_target_index(stack_a, target);
		if (index < stack_a->node_len / 2)
		{
			cost->ra = index;
		}
		else
		{
			cost->rra = stack_a->node_len - index;
		}
		if (i < stack_b->node_len / 2)
		{
			cost->ra = i;
		}
		else
		{
			cost->rra = stack_b->node_len - i;
		}
		if (compere_cost(cost, min_cost))
			min_cost = cost;
		i++;
	}
	return (min_cost);
}
