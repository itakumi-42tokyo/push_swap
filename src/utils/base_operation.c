/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 15:32:31 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// 構造体の中身を書き換えたいときは、別にシングルポインタで構わないよ。
void	sa(t_root *stack_a)
{
	int		tmp;
	t_list	*first_node;

	write(1, "sa\n", 3);
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

	write(1, "sb\n", 3);
	first_node = (stack_b->sentinel)->next;
	tmp = first_node->number;
	first_node->number = first_node->next->number;
	first_node->next->number = tmp;
}

void	ss(t_root *stack_a, t_root *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(2, "ss\n", 3);
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
	stack_a->node_len += 1;
	stack_b->node_len -= 1;
	write(1, "pa\n", 3);
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
	stack_b->node_len += 1;
	stack_a->node_len -= 1;
	write(1, "pb\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_root *stack_a, t_root *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rrr(t_root *stack_a, t_root *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
