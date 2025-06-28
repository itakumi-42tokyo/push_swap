/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 09:45:56 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// 構造体の中身を書き換えたいときは、別にシングルポインタで構わないよ。
void	sa(t_root *stack_a)
{
	int		tmp;
	t_list	*first_node;

	first_node = (stack_a->sentinel)->next;
	tmp = first_node->number;
	first_node->number = first_node->next->number;
	first_node->next->number = tmp;
}

// 方針としては、変更するときのみアドレスを渡す感じで、
void	sb(t_root *stack_b)
{
	int		tmp;
	t_list	*first_node;

	first_node = (stack_b->sentinel)->next;
	tmp = first_node->number;
	first_node->number = first_node->next->number;
	first_node->next->number = tmp;
}

void	ss(t_root *stack_a, t_root *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// pushは移動が起きるたびにfreeするべきか？
// そうしないと、循環リストが成り立たなくなってしまう。というか面倒
// mallocできなかったら、すべての処理を終了しよう。

int	pa(t_root *stack_a, t_root *stack_b)
{
	int		tmp;
	t_list	*first_node_b;
	t_list	*new_node;

	if (stack_a == NULL || stack_b == NULL)
		return (0);
	first_node_b = (stack_b->sentinel)->next;
	tmp = first_node_b->number;
	first_node_b->next->prev = stack_b->sentinel;
	stack_b->sentinel->next = first_node_b->next;
	free(first_node_b);
	// first_node_b->prev->next = first_node_b->next;
	new_node = ut_create_node(stack_a, tmp);
	if (new_node == NULL)
		return (-1);
	// first_node_a->prev = new_node;
	// stack_a->sentinel->next = new_node;
	// new_node->prev = stack_a->sentinel;
	// new_node->next = first_node_a;
	// first_node_a = new_node;// same?
	// create_node
	// そこに情報だけ書き込む感じ
	return (0);
}

int	pb(t_root *stack_a, t_root *stack_b)
{
	int		tmp;
	t_list	*first_node_a;
	t_list	*new_node;

	if (stack_a == NULL || stack_b == NULL)
		return (-1);
	first_node_a = (stack_a->sentinel)->next;
	tmp = first_node_a->number;
	(first_node_a->next)->prev = stack_a->sentinel;
	(stack_a->sentinel)->next = first_node_a->next;
	free(first_node_a);
	new_node = ut_create_node(stack_b, tmp);
	if (new_node == NULL)
		return (-1);
	// temp = first_node_b->prev;
	// first_node_b->prev = new_node;
	// temp->next = new_node;
	// new_node->prev = temp;
	// new_node->next = first_node_b;
	// first_node_b = new_node;
	return (0);
}


//sentinelをつなぎ変えないといけない。
void	ra(t_root *stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = (stack_a->sentinel)->next;
	last_node = (stack_a->sentinel)->prev;
	first_node->next->prev = (stack_a)->sentinel;
	(stack_a->sentinel)->next = first_node->next;
	last_node->next = first_node;
	(stack_a->sentinel)->prev = first_node;
	first_node->prev = last_node;
	first_node->next = stack_a->sentinel;
}

void	rb(t_root *stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = (stack_b->sentinel)->next;
	last_node = (stack_b->sentinel)->prev;
	first_node->next->prev = (stack_b)->sentinel;
	last_node->next = first_node;
	(stack_b->sentinel)->next = first_node->next;
	first_node->prev = last_node;
	first_node->next = stack_b->sentinel;
}

void	rr(t_root *stack_a, t_root *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_root *stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = (stack_a->sentinel)->next;
	last_node = (stack_a->sentinel)->prev;
	(last_node->prev)->next = stack_a->sentinel;
	stack_a->sentinel->prev = last_node->prev;
	stack_a->sentinel->next = last_node;
	last_node->prev = stack_a->sentinel;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	rrb(t_root *stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = (stack_b->sentinel)->next;
	last_node = (stack_b->sentinel)->prev;
	(last_node->prev)->next = stack_b->sentinel;
	stack_b->sentinel->prev = last_node->prev;
	stack_b->sentinel->next = last_node;
	last_node->prev = stack_b->sentinel;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	rrr(t_root *stack_a, t_root *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
