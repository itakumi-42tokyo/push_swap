/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
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
** Internal rotate helper without printing
*/
static void	rotate_internal(t_root *stack)
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
}

/*
** Internal reverse rotate helper without printing
*/
static void	reverse_rotate_internal(t_root *stack)
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
}

/*
** Rotate both stacks upward simultaneously
*/
void	rr(t_root *stack_a, t_root *stack_b)
{
	rotate_internal(stack_a);
	rotate_internal(stack_b);
	write(1, "rr\n", 3);
}

/*
** Reverse rotate both stacks simultaneously
*/
void	rrr(t_root *stack_a, t_root *stack_b)
{
	reverse_rotate_internal(stack_a);
	reverse_rotate_internal(stack_b);
	write(1, "rrr\n", 4);
}
