/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/05 18:00:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

/*
** Initialize cost structure to zero
*/
static void	init_cost_zero(t_cost *cost)
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
static int	total_cost(t_cost *cost)
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
static void	set_cost_for_pb(
	t_root *stack_a, t_root *stack_b, t_cost *cost, int i, int num)
{
	int	target;
	int	index;

	target = get_prev_number(num, stack_b);
	index = get_target_index(stack_b, target);
	if (index <= stack_b->node_len / 2)
		cost->rb = index;
	else
		cost->rrb = stack_b->node_len - index;
	if (i <= stack_a->node_len / 2)
		cost->ra = i;
	else
		cost->rra = stack_a->node_len - i;
}

/*
** Set cost for pushing element back to A
*/
static void	set_cost_for_pa(
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

/*
** Calculate costs for all push to B candidates
*/
t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f)
{
	t_cost	*cost;
	t_cost	*min_cost;
	t_list	*cur_a;
	int		i;

	min_cost = NULL;
	cur_a = stack_a->sentinel->next;
	i = 0;
	while (cur_a != stack_a->sentinel)
	{
		if (lis_f == false || cur_a->lis == false)
		{
			cost = malloc(sizeof(t_cost));
			if (!cost)
				return (min_cost);
			init_cost_zero(cost);
			set_cost_for_pb(stack_a, stack_b, cost, i, cur_a->number);
			minimize_cost(&cost);
			if (min_cost == NULL || total_cost(cost) < total_cost(min_cost))
			{
				free(min_cost);
				min_cost = cost;
			}
			else
				free(cost);
		}
		cur_a = cur_a->next;
		i++;
	}
	return (min_cost);
}

/*
** Calculate costs for all push to A candidates
*/
t_cost	*count_cost_pa(t_root *stack_a, t_root *stack_b)
{
	t_cost	*cost;
	t_cost	*min_cost;
	t_list	*cur_b;
	int		i;

	min_cost = NULL;
	cur_b = stack_b->sentinel->next;
	i = 0;
	while (cur_b != stack_b->sentinel)
	{
		cost = malloc(sizeof(t_cost));
		if (!cost)
			return (min_cost);
		init_cost_zero(cost);
		set_cost_for_pa(stack_a, stack_b, cost, i);
		minimize_cost(&cost);
		if (min_cost == NULL || total_cost(cost) < total_cost(min_cost))
		{
			free(min_cost);
			min_cost = cost;
		}
		else
			free(cost);
		cur_b = cur_b->next;
		i++;
	}
	return (min_cost);
}
