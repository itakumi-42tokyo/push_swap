/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:02:37 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/04 14:38:02 by itakumi          ###   ########.fr       */
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
	int		len;
	int		*numbers;
	int		next_number;
	t_list	*cur;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return (-1);// 審議
	// 一度、ソートしてから、やりたいが数字を取り出す必要がある。
	cur = linked_list->sentinel->next;
	len = 0;
	while (cur != linked_list->sentinel)
	{
		cur = cur->next;
		len++;
	}
	numbers = malloc(sizeof(int) * len);
	if (numbers == NULL)
		return (-1);
	i = 0;
	cur = cur->next;
	while (cur != linked_list->sentinel)
	{
		numbers[i++] = cur->number;
		cur = cur->next;
	}
	quick_sort(numbers, 0, len - 1);
	i = 0;
	while (i < len)
	{
		if (numbers[i] > now)
			return (next_number = numbers[i], free(numbers), next_number);
		i++;
	}
	next_number = numbers[i];
	free(numbers);
	return (next_number);
}

// // pa専用
// int	get_prev_number(int now, t_root *linked_list)
// {

// }
