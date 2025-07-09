/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:41:48 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 18:48:29 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

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
