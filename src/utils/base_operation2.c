/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:47:13 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/30 16:54:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

void	print_node(t_singl *singl)
{
	if (singl == NULL)
		return ;
	while (singl)
	{
		write(1, singl->operation, ft_strlen(singl->operation));
		write(1, "\n", 1);
		singl = singl->next;
	}
}

// これはリストの長さから計算する必要がある

#include <stdio.h>
void	put_min_top(t_root *stack_a)
{
	int		min;
	int		index;

	min = get_min(stack_a);
	index = get_target_index(stack_a, min);
	if (index == 0)
		return ;
	else if (index == 1)
	{
		sa(stack_a);
		write(2, "sa\n", 3);
	}
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
		write(2, "ra\nra\n", 6);
	}
	else if (index == 3)
	{
		rra(stack_a);
		write(1, "rra\n", 5);
	}
}

// ソートされていいるかどうかを確認する関数

int	check_sorted_s(t_root *stack)
{
	t_list	*cur;

	if (stack == NULL)
		return (0);
	cur = (stack->sentinel)->next;
	while (cur->next != stack->sentinel)
	{
		if (cur->number > (cur->next)->number)
			return (0);
		cur = cur->next;
	}
	return (1);
}
