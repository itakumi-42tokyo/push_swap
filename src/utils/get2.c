/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:58:12 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:59:31 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// Fill numbers array from linked list
int	fill_numbers_from_list(t_root *linked_list, int *numbers)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = linked_list->sentinel->next;
	while (cur != linked_list->sentinel)
	{
		numbers[i] = cur->number;
		cur = cur->next;
		i++;
	}
	return (0);
}
