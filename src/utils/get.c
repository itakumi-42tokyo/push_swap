/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:02:37 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:57:55 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// Find index of target number in the list
int	get_target_index(t_root *linked_list, int target)
{
	int		index;
	t_list	*cur;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return (-1);
	index = 0;
	cur = linked_list->sentinel->next;
	while (cur != linked_list->sentinel)
	{
		if (cur->number == target)
			return (index);
		cur = cur->next;
		index++;
	}
	return (-1);
}

// Find first number greater than 'now' in sorted array
int	find_next_in_sorted(int *numbers, int len, int now)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (numbers[i] > now)
			return (numbers[i]);
		i++;
	}
	return (numbers[0]);
}

// Find last number smaller than 'now' in sorted array
int	find_prev_in_sorted(int *numbers, int len, int now)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		if (numbers[i] < now)
			return (numbers[i]);
		i--;
	}
	return (numbers[len - 1]);
}

// Find next bigger number than 'now'; if not found, return smallest
int	get_next_number(int now, t_root *linked_list)
{
	int		*numbers;
	int		next_number;

	if (!linked_list || !linked_list->sentinel || linked_list->node_len == 0)
		return (-1);
	numbers = malloc(sizeof(int) * linked_list->node_len);
	if (!numbers)
		return (-1);
	fill_numbers_from_list(linked_list, numbers);
	quick_sort(numbers, 0, linked_list->node_len - 1);
	next_number = find_next_in_sorted(numbers, linked_list->node_len, now);
	free(numbers);
	return (next_number);
}

// Find previous smaller number than 'now'; if not found, return biggest
int	get_prev_number(int now, t_root *linked_list)
{
	int		*numbers;
	int		prev_number;

	if (!linked_list || !linked_list->sentinel || linked_list->node_len == 0)
		return (-1);
	numbers = malloc(sizeof(int) * linked_list->node_len);
	if (!numbers)
		return (-1);
	fill_numbers_from_list(linked_list, numbers);
	quick_sort(numbers, 0, linked_list->node_len - 1);
	prev_number = find_prev_in_sorted(numbers, linked_list->node_len, now);
	free(numbers);
	return (prev_number);
}
