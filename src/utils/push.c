/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 18:43:23 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// pushは移動が起きるたびにfreeするべきか？
// そうしないと、循環リストが成り立たなくなってしまう。というか面倒
// mallocできなかったら、すべての処理を終了しよう。

int	pa(t_root *stack_a, t_root *stack_b)
{
	int		tmp;
	bool	lis_f;
	t_list	*first_node_b;
	t_list	*new_node;

	if (stack_a == NULL || stack_b == NULL)
		return (0);
	first_node_b = (stack_b->sentinel)->next;
	tmp = first_node_b->number;
	first_node_b->next->prev = stack_b->sentinel;
	stack_b->sentinel->next = first_node_b->next;
	lis_f = first_node_b->lis;
	free(first_node_b);
	new_node = ut_create_node(stack_a, tmp, lis_f);
	if (new_node == NULL)
		return (-1);
	stack_a->node_len += 1;
	stack_b->node_len -= 1;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_root *stack_a, t_root *stack_b)
{
	int		tmp;
	bool	lis_f;
	t_list	*first_node_a;
	t_list	*new_node;

	if (stack_a == NULL || stack_b == NULL)
		return (-1);
	first_node_a = (stack_a->sentinel)->next;
	tmp = first_node_a->number;
	(first_node_a->next)->prev = stack_a->sentinel;
	(stack_a->sentinel)->next = first_node_a->next;
	lis_f = first_node_a->lis;
	free(first_node_a);
	new_node = ut_create_node(stack_b, tmp, lis_f);
	if (new_node == NULL)
		return (-1);
	stack_b->node_len += 1;
	stack_a->node_len -= 1;
	write(1, "pb\n", 3);
	return (0);
}
