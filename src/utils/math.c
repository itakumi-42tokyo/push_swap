/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 20:06:07 by itakumi          ###   ########.fr       */
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

int	ut_top_node_ismin(t_root *linked_list)
{
	int		top_number;
	t_list	*current;

	current = (linked_list->sentinel)->next;
	top_number = current->number;
	current =current->next;
	while (current != linked_list->sentinel)
	{
		if (top_number > current->number)
			return (0);
		current = current->next;
	}
	return (1);
}

//これらは重複がない前提。
int	ut_top_node_ismax(t_root *linked_list)
{
	int		top_number;
	t_list	*current;

	current = (linked_list->sentinel)->next;
	top_number = current->number;
	current = current->next;
	while (current != linked_list->sentinel)
	{
		if (top_number < current->number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ut_top_node_ismid(t_root *linked_list)
{
	if (!ut_top_node_ismin(linked_list)
		&& !ut_top_node_ismax(linked_list))
		return (1);
	return (0);
}

int	ut_tail_node_ismax(t_root *linked_list)
{
	int		tail_number;
	t_list	*current;

	current = (linked_list->sentinel)->prev;
	tail_number = current->number;
	current = current->prev;
	while (current != linked_list->sentinel)
	{
		if (tail_number < current->number)
			return (0);
		current = current->prev;
	}
	return (1);
}

int	ut_tail_node_ismin(t_root *linked_list)
{
	int		tail_number;
	t_list	*current;

	current = (linked_list->sentinel)->prev;
	tail_number = current->number;
	current = current->prev;
	while (current != linked_list->sentinel)
	{
		if (tail_number > current->number)
			return (0);
		current = current->prev;
	}
	return (1);
}

int	ut_tail_node_ismid(t_root *linked_list)
{
	if (!ut_tail_node_ismin(linked_list)
		&& !ut_tail_node_ismax(linked_list))
		return (1);
	return (0);
}
