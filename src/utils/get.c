/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:02:37 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/05 18:40:42 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

int	get_target_index(t_root *linked_list, int target)
{
	int		index;
	t_list	*cur;

	index = 0;
	cur = (linked_list->sentinel)->next;
	while (cur != (linked_list->sentinel))
	{
		if (cur->number == target)
			return (index);
		cur = cur->next;
		index++;
	}
	return (-1);
}

// limit以上のmax値を探そう。　差をとって、一番近いものを採用しよう。
//　差が１しかないので、どう判別しよう。　
// これらをソートしてから、より大きくなったものの初めを返せば良いな。

int	get_next_number(int	now, t_root *linked_list)
{
	int		i;
	int		*numbers;
	int		next_number;
	t_list	*cur;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return (-1);// 審議
	if (linked_list->node_len == 0)
		return (-1);
	// 一度、ソートしてから、やりたいが数字を取り出す必要がある。
	cur = linked_list->sentinel->next;
	numbers = malloc(sizeof(int) * linked_list->node_len);
	if (numbers == NULL)
		return (-1);
	i = 0;
	while (cur != linked_list->sentinel)
	{
		numbers[i++] = cur->number;
		cur = cur->next;
	}
	quick_sort(numbers, 0, linked_list->node_len - 1);
	i = 0;
	while (i < linked_list->node_len)
	{
		if (numbers[i] > now)
			return (next_number = numbers[i], free(numbers), next_number);
		i++;
	}
	next_number = numbers[0];
	free(numbers);
	return (next_number);
}

// // pa専用
int	get_prev_number(int now, t_root *linked_list)
{
	int		i;
	int		*numbers;
	int		prev_number;
	t_list	*cur;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return (-1);// 審議
	if (linked_list->node_len == 0)
		return (-1);
	// 一度、ソートしてから、やりたいが数字を取り出す必要がある。
	cur = linked_list->sentinel->next;
	numbers = malloc(sizeof(int) * linked_list->node_len);
	if (numbers == NULL)
		return (-1);
	i = 0;
	while (cur != linked_list->sentinel)
	{
		numbers[i++] = cur->number;
		cur = cur->next;
	}
	quick_sort(numbers, 0, linked_list->node_len - 1);
	i = linked_list->node_len;
	while (i >= 0)
	{
		if (numbers[i] < now)
			return (prev_number = numbers[i], free(numbers), prev_number);
		i--;
	}
	prev_number = numbers[linked_list->node_len];
	free(numbers);
	return (prev_number);
}
