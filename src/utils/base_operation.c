/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/05 17:41:13 by itakumi          ###   ########.fr       */
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

// === internal helpers that DO NOT print ===
static void	swap_first_two(t_root *stack)
{
	if (stack == NULL || stack->node_len < 2)
		return ;
	int		 tmp;
	t_list	*first;

	first = stack->sentinel->next;
	tmp = first->number;
	first->number = first->next->number;
	first->next->number = tmp;
}

static void	rotate_up_noprint(t_root *stack)
{
	if (stack == NULL || stack->node_len < 2)
		return ;
	t_list *first = stack->sentinel->next;
	t_list *last = stack->sentinel->prev;
	stack->sentinel->next = first->next;
	first->next->prev = stack->sentinel;
	first->next = stack->sentinel;
	first->prev = last;
	last->next = first;
	stack->sentinel->prev = first;
}

static void	rotate_down_noprint(t_root *stack)
{
	if (stack == NULL || stack->node_len < 2)
		return ;
	t_list *first = stack->sentinel->next;
	t_list *last = stack->sentinel->prev;
	stack->sentinel->prev = last->prev;
	last->prev->next = stack->sentinel;
	last->prev = stack->sentinel;
	last->next = first;
	first->prev = last;
	stack->sentinel->next = last;
}

void	ss(t_root *stack_a, t_root *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	write(1, "ss\n", 3);
}

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
	// first_node_b->prev->next = first_node_b->next;
	new_node = ut_create_node(stack_a, tmp, lis_f);
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

// ポインタを変更するのは面倒なので、LISと数字のみを変更するプログラムに修正しよう。
//sentinelをつなぎ変えないといけない。
// void	ra(t_root *stack_a)
// {
// 	t_list	*first_node;
// 	t_list	*last_node;

// 	if (stack_a->node_len < 2)
// 		return ;
// 	first_node = (stack_a->sentinel)->next;
// 	last_node = (stack_a->sentinel)->prev;
// 	first_node->next->prev = (stack_a)->sentinel;
// 	(stack_a->sentinel)->next = first_node->next;
// 	last_node->next = first_node;
// 	(stack_a->sentinel)->prev = first_node;
// 	first_node->prev = last_node;
// 	first_node->next = stack_a->sentinel;
// 	write(1, "ra\n", 3);
// }

// void	rb(t_root *stack_b)
// {
// 	t_list	*first_node;
// 	t_list	*last_node;

// 	if (stack_b->node_len < 2)
// 		return ;
// 	first_node = (stack_b->sentinel)->next;
// 	last_node = (stack_b->sentinel)->prev;
// 	first_node->next->prev = (stack_b)->sentinel;
// 	last_node->next = first_node;
// 	(stack_b->sentinel)->next = first_node->next;
// 	first_node->prev = last_node;
// 	first_node->next = stack_b->sentinel;
// 	write(1, "rb\n", 3);
// }

#include "push_swap.h" // ヘッダファイル名はご自身のものに合わせてください

// stack_aを上方向に回転 (rotate a)
void ra(t_root *stack)
{
    t_list *first;
    t_list *last;

    // 【修正点】要素数が2未満の場合は何もせず処理を終える (ルール準拠)
    if (stack == NULL || stack->node_len < 2)
        return;

    first = stack->sentinel->next;
    last = stack->sentinel->prev;

    // ポインタの繋ぎ変え
    stack->sentinel->next = first->next; // sentinelの次を、2番目の要素に
    first->next->prev = stack->sentinel; // 2番目の要素の前を、sentinelに

    first->next = stack->sentinel; // 元の先頭要素の次をsentinelに (末尾へ)
    first->prev = last;            // 元の先頭要素の前を、元の末尾要素に

    last->next = first;                // 元の末尾要素の次を、元の先頭要素に
    stack->sentinel->prev = first; // sentinelの前を、新しい末尾(元の先頭)に

    write(1, "ra\n", 3);
}

// stack_bを上方向に回転 (rotate b)
void rb(t_root *stack)
{
    t_list *first;
    t_list *last;

    // 【修正点】要素数が2未満の場合は何もせず処理を終える
    if (stack == NULL || stack->node_len < 2)
        return;

    first = stack->sentinel->next;
    last = stack->sentinel->prev;

    stack->sentinel->next = first->next;
    first->next->prev = stack->sentinel;

    first->next = stack->sentinel;
    first->prev = last;

    last->next = first;
    stack->sentinel->prev = first;

    write(1, "rb\n", 3);
}

// もし、stack_aまたは、stack_bのnode_lenが１以下だったら、どう処理をするべきか。
// そもそも、この関数を呼び出しているものは何であり、どのような制限をつけているのだろうか。
void	rr(t_root *stack_a, t_root *stack_b)
{
	rotate_up_noprint(stack_a);
	rotate_up_noprint(stack_b);
	write(1, "rr\n", 3);
}

// void	rra(t_root *stack_a)
// {
// 	t_list	*first_node;
// 	t_list	*last_node;

// 	if (stack_a->node_len < 2)
// 		return ;
// 	first_node = (stack_a->sentinel)->next;
// 	last_node = (stack_a->sentinel)->prev;
// 	(last_node->prev)->next = stack_a->sentinel;
// 	stack_a->sentinel->prev = last_node->prev;
// 	stack_a->sentinel->next = last_node;
// 	last_node->prev = stack_a->sentinel;
// 	last_node->next = first_node;
// 	first_node->prev = last_node;
// 	write(1, "rra\n", 4);
// }

// void	rrb(t_root *stack_b)
// {
// 	t_list	*first_node;
// 	t_list	*last_node;

// 	if (stack_b->node_len < 2)
// 		return ;
// 	first_node = (stack_b->sentinel)->next;
// 	last_node = (stack_b->sentinel)->prev;
// 	(last_node->prev)->next = stack_b->sentinel;
// 	stack_b->sentinel->prev = last_node->prev;
// 	stack_b->sentinel->next = last_node;
// 	last_node->prev = stack_b->sentinel;
// 	last_node->next = first_node;
// 	first_node->prev = last_node;
// 	write(1, "rrb\n", 4);
// }

// stack_aを下方向に回転 (reverse rotate a)
void rra(t_root *stack)
{
    t_list *first;
    t_list *last;

    // 【修正点】要素数が2未満の場合は何もせず処理を終える
    if (stack == NULL || stack->node_len < 2)
        return;

    first = stack->sentinel->next;
    last = stack->sentinel->prev;

    // ポインタの繋ぎ変え
    stack->sentinel->prev = last->prev; // sentinelの前を、最後から2番目の要素に
    last->prev->next = stack->sentinel; // 最後から2番目の要素の次を、sentinelに

    last->prev = stack->sentinel;       // 元の末尾要素の前を、sentinelに (先頭へ)
    last->next = first;                 // 元の末尾要素の次を、元の先頭要素に

    first->prev = last;                 // 元の先頭要素の前を、新しい先頭(元の末尾)に
    stack->sentinel->next = last;       // sentinelの次を、新しい先頭要素に

    write(1, "rra\n", 4);
}


// stack_bを下方向に回転 (reverse rotate b)
void rrb(t_root *stack)
{
    t_list *first;
    t_list *last;

    // 【修正点】要素数が2未満の場合は何もせず処理を終える
    if (stack == NULL || stack->node_len < 2)
        return;

    first = stack->sentinel->next;
    last = stack->sentinel->prev;

    stack->sentinel->prev = last->prev;
    last->prev->next = stack->sentinel;

    last->prev = stack->sentinel;
    last->next = first;

    first->prev = last;
    stack->sentinel->next = last;

    write(1, "rrb\n", 4);
}

void	rrr(t_root *stack_a, t_root *stack_b)
{
	rotate_down_noprint(stack_a);
	rotate_down_noprint(stack_b);
	write(1, "rrr\n", 4);
}
