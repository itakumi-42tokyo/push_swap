/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:40:44 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 18:41:42 by itakumi          ###   ########.fr       */
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

void	ss(t_root *stack_a, t_root *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	write(1, "ss\n", 3);
}
