/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:49:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:47:48 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Helper: update min_cost pointer
*/
void	update_min_cost(t_cost **min_cost, t_cost *candidate)
{
	if (!candidate)
		return ;
	if (*min_cost == NULL || total_cost(candidate) < total_cost(*min_cost))
	{
		free(*min_cost);
		*min_cost = candidate;
	}
	else
		free(candidate);
}

/*
** Initialize cost structure to zero
*/
void	init_cost_zero(t_cost *cost)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rrr = 0;
}

/*
** Calculate total cost of all operations
*/
int	total_cost(t_cost *cost)
{
	int	total;

	total = 0;
	total += cost->ra;
	total += cost->rb;
	total += cost->rr;
	total += cost->rra;
	total += cost->rrb;
	total += cost->rrr;
	return (total);
}

/*
** Set cost for pushing element to B
*/
void	set_cost_for_pb(
	t_root *stack_a, t_root *stack_b, t_cost *cost, int idx0_num1[])
{
	int	target;
	int	index;

	target = get_prev_number(idx0_num1[1], stack_b);
	index = get_target_index(stack_b, target);
	if (index <= stack_b->node_len / 2)
		cost->rb = index;
	else
		cost->rrb = stack_b->node_len - index;
	if (idx0_num1[0] <= stack_a->node_len / 2)
		cost->ra = idx0_num1[0];
	else
		cost->rra = stack_a->node_len - idx0_num1[0];
}

/*
** Set cost for pushing element back to A
*/
void	set_cost_for_pa(
	t_root *stack_a, t_root *stack_b, t_cost *cost, int i)
{
	int	target;
	int	index;

	target = get_next_number(stack_b->sentinel->next->number, stack_a);
	index = get_target_index(stack_a, target);
	if (index <= stack_a->node_len / 2)
		cost->ra = index;
	else
		cost->rra = stack_a->node_len - index;
	if (i <= stack_b->node_len / 2)
		cost->rb = i;
	else
		cost->rrb = stack_b->node_len - i;
}
