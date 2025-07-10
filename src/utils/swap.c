/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:40:44 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:53:55 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Swap first two elements of stack A
*/
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

/*
** Swap first two elements of stack B
*/
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

/*
** Internal helper that swaps without printing
*/
static void	swap_first_two(t_root *stack)
{
	int		tmp;
	t_list	*first;

	if (stack == NULL || stack->node_len < 2)
		return ;
	first = stack->sentinel->next;
	tmp = first->number;
	first->number = first->next->number;
	first->next->number = tmp;
}

/*
** Swap first two elements of both stacks
*/
void	ss(t_root *stack_a, t_root *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	write(1, "ss\n", 3);
}
