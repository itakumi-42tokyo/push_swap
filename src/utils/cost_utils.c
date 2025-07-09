/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:05:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 19:39:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

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
