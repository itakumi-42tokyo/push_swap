/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 23:25:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// 連結リストの場合はリストの数を与えないといけないな。
// 番兵ノードを追加するべき
// t_rootを二重ポインタにすれば、nodeの方も変更できるのか？
// max値を返してくれる関数も欲しいのか？

int	get_max(t_root *linked_list)
{
	int		max;
	t_list	*current;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return (-1);
	current = (linked_list->sentinel)->next;
	max = current->number;
	while (current != linked_list->sentinel)
	{
		if (max < current->number)
			max = current->number;
		current = current->next;
	}
	return (max);
}

int	get_min(t_root *linked_list)
{
	int		min;
	t_list	*cur;

	cur = (linked_list->sentinel)->next;
	min = cur->number;
	while (cur != linked_list->sentinel)
	{
		if (min > cur->number)
			min = cur->number;
		cur = cur->next;
	}
	return (min);
}
