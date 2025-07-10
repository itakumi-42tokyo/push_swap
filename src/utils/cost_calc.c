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
** Helper: create cost struct for a PB candidate
*/
static t_cost	*generate_pb_cost(t_root *a, t_root *b, int idx, int num)
{
    t_cost *cost;

    cost = malloc(sizeof(t_cost));
    if (!cost)
        return (NULL);
    init_cost_zero(cost);
    set_cost_for_pb(a, b, cost, idx, num);
    minimize_cost(&cost);
    return (cost);
}

/*
** Helper: create cost struct for a PA candidate
*/
static t_cost	*generate_pa_cost(t_root *a, t_root *b, int idx)
{
    t_cost *cost;

    cost = malloc(sizeof(t_cost));
    if (!cost)
        return (NULL);
    init_cost_zero(cost);
    set_cost_for_pa(a, b, cost, idx);
    minimize_cost(&cost);
    return (cost);
}

/*
** Helper: update min_cost pointer
*/
static void	update_min_cost(t_cost **min_cost, t_cost *candidate)
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
** Calculate costs for all push to B candidates
*/
t_cost	*count_cost_pb(t_root *stack_a, t_root *stack_b, bool lis_f)
{
    t_cost  *min_cost;
    t_list  *cur;
    int      idx;

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
    t_cost  *min_cost;
    t_list  *cur;
    int      idx;

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
