/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:47:13 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 06:48:46 by itakumi          ###   ########.fr       */
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

#include <stdio.h>
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
