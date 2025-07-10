/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:26:50 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:51:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

void	print_node(t_singl *singl)
{
	if (singl == NULL)
		return ;
	while (singl)
	{
		write(1, singl->operation, ft_strlen(singl->operation));
		write(1, "\n", 1);
		singl = singl->next;
	}
}

/*
** Move minimum value to top of stack using optimal rotation
** Calculates whether ra or rra is faster based on position
*/
void	put_min_top(t_root *stack_a)
{
	int	min;
	int	index;
	int	len;
	int	rotations;

	min = get_min(stack_a);
	index = get_target_index(stack_a, min);
	len = stack_a->node_len;
	if (index <= len / 2)
	{
		while (index-- > 0)
			ra(stack_a);
	}
	else
	{
		rotations = len - index;
		while (rotations-- > 0)
			rra(stack_a);
	}
}

/*
** Check if stack is sorted in ascending order
** Returns 1 if sorted, 0 otherwise
*/
int	check_sorted_s(t_root *stack)
{
	t_list	*cur;

	if (stack == NULL)
		return (0);
	cur = (stack->sentinel)->next;
	while (cur->next != stack->sentinel)
	{
		if (cur->number > (cur->next)->number)
			return (0);
		cur = cur->next;
	}
	return (1);
}
