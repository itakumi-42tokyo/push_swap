/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:19:27 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:51:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Push top element from stack B to stack A
*/
void	pa(t_root *stack_a, t_root *stack_b)
{
	t_list	*first;

	if (stack_b == NULL || stack_b->node_len == 0)
		return ;
	first = stack_b->sentinel->next;
	stack_b->sentinel->next = first->next;
	first->next->prev = stack_b->sentinel;
	stack_b->node_len--;
	first->next = stack_a->sentinel->next;
	first->prev = stack_a->sentinel;
	stack_a->sentinel->next->prev = first;
	stack_a->sentinel->next = first;
	stack_a->node_len++;
	write(1, "pa\n", 3);
}

/*
** Push top element from stack A to stack B
*/
void	pb(t_root *stack_a, t_root *stack_b)
{
	t_list	*first;

	if (stack_a == NULL || stack_a->node_len == 0)
		return ;
	first = stack_a->sentinel->next;
	stack_a->sentinel->next = first->next;
	first->next->prev = stack_a->sentinel;
	stack_a->node_len--;
	first->next = stack_b->sentinel->next;
	first->prev = stack_b->sentinel;
	stack_b->sentinel->next->prev = first;
	stack_b->sentinel->next = first;
	stack_b->node_len++;
	write(1, "pb\n", 3);
}
