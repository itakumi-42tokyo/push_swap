/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: o3-ai                                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:30:00 by o3-ai             #+#    #+#             */
/*   Updated: 2025/07/06 10:30:00 by o3-ai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

static void	rotate_b_by_index(t_root *b, int idx)
{
	if (idx <= b->node_len / 2)
		while (idx--) rb(b);
	else {
		idx = b->node_len - idx;
		while (idx--) rrb(b);
	}
}

/* keep stack B in strict descending order (top = max) */
void	insert_sorted_pb(t_root *a, t_root *b)
{
	int v;
	int idx;
	t_list *cur;

	if (!a || !b)
		return ;
	v = (a->sentinel)->next->number;
	if (b->node_len < 2) {
		pb(a, b);
		return ;
	}
	/* case: v greater than current max */
	if (v > get_max(b))
	{
		idx = get_target_index(b, get_max(b));
		rotate_b_by_index(b, idx);
		pb(a, b);
		return ;
	}
	/* case: v smaller than current min */
	if (v < get_min(b))
	{
		idx = get_target_index(b, get_min(b));
		rotate_b_by_index(b, idx + 1); // min should become second after rotate
		pb(a, b);
		return ;
	}
	/* general case */
	cur = b->sentinel->next;
	idx = 0;
	while (cur->next != b->sentinel)
	{
		if (cur->number >= v && (cur->next)->number < v)
			break ;
		cur = cur->next;
		idx++;
	}
	rotate_b_by_index(b, idx + 1); // place insertion point at top
	pb(a, b);
} 