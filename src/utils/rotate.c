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

/*
** Rotate stack A upward (first element becomes last)
*/
void	ra(t_root *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || stack->node_len < 2)
		return ;
	first = stack->sentinel->next;
	last = stack->sentinel->prev;
	stack->sentinel->next = first->next;
	first->next->prev = stack->sentinel;
	first->next = stack->sentinel;
	first->prev = last;
	last->next = first;
	stack->sentinel->prev = first;
	write(1, "ra\n", 3);
}

/*
** Rotate stack B upward (first element becomes last)
*/
void	rb(t_root *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || stack->node_len < 2)
		return ;
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

/*
** Reverse rotate stack A (last element becomes first)
*/
void	rra(t_root *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || stack->node_len < 2)
		return ;
	first = stack->sentinel->next;
	last = stack->sentinel->prev;
	stack->sentinel->prev = last->prev;
	last->prev->next = stack->sentinel;
	last->prev = stack->sentinel;
	last->next = first;
	first->prev = last;
	stack->sentinel->next = last;
	write(1, "rra\n", 4);
}

/*
** Reverse rotate stack B (last element becomes first)
*/
void	rrb(t_root *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack == NULL || stack->node_len < 2)
		return ;
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
