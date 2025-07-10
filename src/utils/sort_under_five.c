/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/30 17:51:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>
// ２は確定で、並び替えが発生しないといけないのか。
//  sort系は操作＋操作文字の代入の役割を持っている。

static t_singl	*sort_two(t_root *stack_a, t_singl **singl)
{
	sa(stack_a);
	// lst_all(singl, "sa");
	return (*singl);
}

// すべてのソートを試して、最後に確認する方法を取るのかな
// そのためにすべての操作を記録するための領域が必要かな。
// ソート完了が確認でき次第、mallocしてリターンするべき
// 検証するたびに、値が変更されてしまうのが面倒。

// 座標圧縮するのはこのためか

// 読み取り専用領域を大量に使用してもよいのか？

// 比較する数値は必ず０１２とは限らなかった。

t_singl	*sort_three(t_root *stack_a, t_singl **singl)
{
	int	max;

	(void)singl;
	max = get_max(stack_a);
	if (max == (stack_a->sentinel)->next->number)
		ra(stack_a);
	else if (max == (stack_a->sentinel)->next->next->number)
		rra(stack_a);
	if ((stack_a->sentinel)->next->number > (stack_a->sentinel)->next->next->number)
		sa(stack_a);
	return (NULL);
}

// stack_bを用意して、入れ込んでいく。
// オペレーションの文字列も構造体にしたほうが管理しやすい気がしてきた。
// sort_threeの引数にt_singlを入れたほうが良いのか？
// sorted系には必ずその要素数の物しか引数を受け付けないという風になっている
// 返り値は何にしよう。

// どこにstack_bの変数を入れるか決めないといけないな。
// 上から小さい順になっているので，入れるために

// そもそも操作は実行した瞬間に出力すればよいのか。

static t_singl	*sort_four(t_root *stack_a, t_root *stack_b, t_singl **singl)
{
	put_min_top(stack_a);
	if (check_sorted_s(stack_a) == 1)
		return (*singl);
	pb(stack_a, stack_b);
	// lst_all(singl, "pb");
	sort_three(stack_a, singl);
	pa(stack_a, stack_b);
	return (*singl);
}

// 今後sorted_over_sixと組み合わせる可能性があるので，拡張性を持たせるために，操作文字列リストも受け取るようにしたほうが良いな。
// 一旦，何も考えずに，最小値２つをプッシュしてみる。
// ２番に最小なものをまず見つける。
// paするときに、どのように入れるかが鍵になってくる。
// 一つ前の数字を戦闘に持っていきたいから
// すでにソートされたものに対しては、index でraかrraかを判断するしかないのか？

static void	push_two_smallest(t_root *stack_a, t_root *stack_b)
{
	put_min_top(stack_a);
	pb(stack_a, stack_b);
	put_min_top(stack_a);
	pb(stack_a, stack_b);
}

static void	merge_three_and_push_back(t_root *stack_a, t_root *stack_b)
{
	sort_three(stack_a, NULL);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static t_singl	*sort_five(t_root *stack_a, t_root *stack_b, t_singl **singl)
{
	push_two_smallest(stack_a, stack_b);
	merge_three_and_push_back(stack_a, stack_b);
	return (*singl);
}

t_singl	*sort_under_five(int argc, t_root *stack_a)
{
	t_root	*stack_b;
	t_singl	*operation;

	operation = NULL;
	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	if (argc == 3)
		sort_two(stack_a, &operation);
	else if (argc == 4)
		sort_three(stack_a, &operation);
	else if (argc == 5)
		sort_four(stack_a, stack_b, &operation);
	else
		sort_five(stack_a, stack_b, &operation);
	cdll_clear(&stack_b, cdll_delone);
	return (operation);
}
