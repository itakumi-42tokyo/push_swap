/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:47:49 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

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

/*
** Helper: create cost struct for a PB candidate
*/
static t_cost	*generate_pb_cost(t_root *a, t_root *b, int idx, int num)
{
	t_cost	*cost;
	int		idx0_num1[2];

	idx0_num1[0] = idx;
	idx0_num1[1] = num;
	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	init_cost_zero(cost);
	set_cost_for_pb(a, b, cost, idx0_num1);
	minimize_cost(&cost);
	return (cost);
}

/*
** Helper: create cost struct for a PA candidate
*/
static t_cost	*generate_pa_cost(t_root *a, t_root *b, int idx)
{
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	init_cost_zero(cost);
	set_cost_for_pa(a, b, cost, idx);
	minimize_cost(&cost);
	return (cost);
}

/*
** Calculate costs for all push to B candidates
*/
t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f)
{
	t_cost	*min_cost;
	t_list	*cur;
	int		idx;

	min_cost = NULL;
	cur = stack_a->sentinel->next;
	idx = 0;
	while (cur != stack_a->sentinel)
	{
		if (lis_f == false || cur->lis == false)
			update_min_cost(&min_cost,
				generate_pb_cost(stack_a, stack_b, idx, cur->number));
		cur = cur->next;
		idx++;
	}
	return (min_cost);
}

/*
** Calculate costs for all push to A candidates
*/
t_cost	*count_cost_pa(t_root *stack_a, t_root *stack_b)
{
	t_cost	*min_cost;
	t_list	*cur;
	int		idx;

	min_cost = NULL;
	cur = stack_b->sentinel->next;
	idx = 0;
	while (cur != stack_b->sentinel)
	{
		update_min_cost(&min_cost,
			generate_pa_cost(stack_a, stack_b, idx));
		cur = cur->next;
		idx++;
	}
	return (min_cost);
}
