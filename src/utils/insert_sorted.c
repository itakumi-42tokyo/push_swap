/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:27:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:57:17 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

static void	rotate_b_by_index(t_root *b, int idx)
{
	if (idx <= b->node_len / 2)
	{
		while (idx--)
			rb(b);
	}
	else
	{
		idx = b->node_len - idx;
		while (idx--)
			rrb(b);
	}
}

/* insert when value is greater than current max in B */
static void	insert_when_max(t_root *a, t_root *b)
{
	int	idx;

	idx = get_target_index(b, get_max(b));
	rotate_b_by_index(b, idx);
	pb(a, b);
}

/* insert when value is smaller than current min in B */
static void	insert_when_min(t_root *a, t_root *b)
{
	int	idx;

	idx = get_target_index(b, get_min(b));
	rotate_b_by_index(b, idx + 1);
	pb(a, b);
}

/* insert when value should go between nodes in B */
static void	insert_between_nodes(t_root *a, t_root *b, int v)
{
	t_list	*cur;
	int		idx;

	cur = b->sentinel->next;
	idx = 0;
	while (cur->next != b->sentinel)
	{
		if (cur->number >= v && cur->next->number < v)
			break ;
		cur = cur->next;
		idx++;
	}
	rotate_b_by_index(b, idx + 1);
	pb(a, b);
}

void	insert_sorted_pb(t_root *a, t_root *b)
{
	int	v;

	if (!a || !b)
		return ;
	v = a->sentinel->next->number;
	if (b->node_len < 2)
		pb(a, b);
	else if (v > get_max(b))
		insert_when_max(a, b);
	else if (v < get_min(b))
		insert_when_min(a, b);
	else
		insert_between_nodes(a, b, v);
}
