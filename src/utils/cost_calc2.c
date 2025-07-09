/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:49:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:50:31 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

void	count_cost_process(t_root *stack_a, t_cost **min_cost)
{
	int		index;
	t_list	*cur_a;

	cur_a = stack_a->sentinel->next;
	index = 0;
	init_cost(min_cost);
	while (cur_a != stack_a->sentinel)
	{
		if (cur_a->lis == false)
		{
			if (index <= stack_a->node_len / 2)
				(*min_cost)->ra = index;
			else
				(*min_cost)->rra = stack_a->node_len - index;
			break ;
		}
		cur_a = cur_a->next;
		index++;
	}
}
