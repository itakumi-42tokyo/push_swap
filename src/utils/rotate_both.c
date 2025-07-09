/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:45:49 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 18:50:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

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

void	rr(t_root *stack_a, t_root *stack_b)
{
	rotate_up_noprint(stack_a);
	rotate_up_noprint(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_root *stack_a, t_root *stack_b)
{
	rotate_down_noprint(stack_a);
	rotate_down_noprint(stack_b);
	write(1, "rrr\n", 4);
}
