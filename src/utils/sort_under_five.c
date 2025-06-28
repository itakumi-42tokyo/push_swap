/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 09:45:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// ２は確定で、並び替えが発生しないといけないのか。
static char	**sort_two(t_root *stack_a)
{
	char	**done;
	sa(stack_a);
	done = ut_produce_double_p("sa", NULL);
	if (done == NULL)
		return (NULL);
	return (done);
}

// すべてのソートを試して、最後に確認する方法を取るのかな
// そのためにすべての操作を記録するための領域が必要かな。
// ソート完了が確認でき次第、mallocしてリターンするべき
// 検証するたびに、値が変更されてしまうのが面倒。

// 座標圧縮するのはこのためか

char	**sort_three(t_root *stack_a)
{
	int		top_number;
	int		mid_number;
	char	**done;

	top_number = (stack_a->sentinel)->next->number;
	mid_number = (stack_a->sentinel)->next->next->number;
	if (top_number == 0 && mid_number == 2)
	{
		rra(stack_a);
		sa(stack_a);
		done = ut_produce_double_p("rra", "sa");
		if (done == NULL)
			return (NULL);
		return (done);
	}
	if (top_number == 1 && mid_number == 0)
	{
		sa(stack_a);
		done = ut_produce_double_p("sa", NULL);
		if (done == NULL)
			return (NULL);
		return (done);
	}
	if (top_number == 1 && mid_number == 2)
	{
		rra(stack_a);
		done = ut_produce_double_p("rra", NULL);
		if (done == NULL)
			return (NULL);
		return (done);
	}
	if (top_number == 2 && mid_number == 1)
	{
		sa(stack_a);
		rra(stack_a);
		done = ut_produce_double_p("sa", "rra");
		if (done == NULL)
			return (NULL);
		return (done);
	}
	if (top_number == 2 && mid_number == 0)
	{
		ra(stack_a);
		done = ut_produce_double_p("ra", NULL);
		if (done == NULL)
			return (NULL);
		return (done);
	}
	return (NULL);
}

// stack_bを用意して、入れ込んでいく。
static char	**sort_four(t_root *stack_a, t_root *stack_b)
{
	char	**done;

	pb(stack_a, stack_b);
	return (done);
}

static char	**sort_five(t_root *stack_a, t_root *stack_b)
{
	(void)stack_a;
	return (0);
}

char	**sort_under_five(int argc, t_root *stack_a)
{
	t_root	*stack_b;
	char	**operation;

	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	if (argc == 3)
		operation = sort_two(stack_a);
	else if (argc == 4)
		operation = sort_three(stack_a);
	else if (argc == 5)
		operation = sort_four(stack_a, stack_b);
	else
		operation = sort_five(stack_a, stack_b);
	cdll_clear(&stack_b, cdll_delone);
	return (operation);
}
