/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:38:38 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:51:05 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

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

static void	process_stack_a(
	t_root *stack_a, t_root *stack_b, bool lis_f, t_cost **min_cost)
{
	t_list	*cur_a;
	t_cost	*cost;
	int		i;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return ;
	cur_a = stack_a->sentinel->next;
	i = 0;
	while (cur_a != stack_a->sentinel)
	{
		if (!(lis_f && cur_a->lis))
		{
			init_cost(&cost);
			set_cost_for_pb(stack_a, stack_b, cost, i, cur_a->number);
			minimize_cost(&cost);
			if (compere_cost(cost, *min_cost) == -1)
				copy_cost(cost, min_cost);
		}
		cur_a = cur_a->next;
		i++;
	}
	free(cost);
}

static void	set_cost_for_pa(
	t_root *stack_a, t_root *stack_b, t_cost *cost, t_list *cur_b)
{
	int	target;
	int	index;

	target = get_next_number(cur_b->number, stack_a);
	index = get_target_index(stack_a, target);
	if (index <= stack_a->node_len / 2)
		cost->ra = index;
	else
		cost->rra = stack_a->node_len - index;
	if (cost->i <= stack_b->node_len / 2)
		cost->rb = cost->i;
	else
		cost->rrb = stack_b->node_len - cost->i;
}

t_cost	*count_cost_pa(t_root *stack_a, t_root *stack_b)
{
	t_cost	*cost;
	t_cost	*min_cost;
	t_list	*cur_b;

	cost = malloc(sizeof(t_cost));
	min_cost = malloc(sizeof(t_cost));
	if (!cost || !min_cost)
		return (free(cost), free(min_cost), NULL);
	init_min_cost(&min_cost);
	cur_b = stack_b->sentinel->next;
	cost->i = 0;
	while (cur_b != stack_b->sentinel)
	{
		init_cost(&cost);
		set_cost_for_pa(stack_a, stack_b, cost, cur_b);
		minimize_cost(&cost);
		if (compere_cost(cost, min_cost) == -1)
			copy_cost(cost, &min_cost);
		cur_b = cur_b->next;
		(cost->i)++;
	}
	return (free(cost), min_cost);
}

t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f)
{
	t_cost	*min_cost;

	min_cost = malloc(sizeof(t_cost));
	if (!min_cost)
		return (NULL);
	init_min_cost(&min_cost);
	if (stack_b->node_len == 0)
	{
		if (lis_f)
			return (count_cost_process(stack_a, &min_cost), min_cost);
		init_cost(&min_cost);
		return (min_cost);
	}
	process_stack_a(stack_a, stack_b, lis_f, &min_cost);
	return (min_cost);
}
