/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/30 17:51:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>

/*
** Sort two elements by swapping if needed
*/
static t_singl	*sort_two(t_root *stack_a, t_singl **singl)
{
	sa(stack_a);
	return (*singl);
}

/*
** Sort three elements using optimal rotation and swap
** Places max element in correct position first, then swaps if needed
*/
t_singl	*sort_three(t_root *stack_a, t_singl **singl)
{
	int	max;

	(void)singl;
	max = get_max(stack_a);
	if (max == (stack_a->sentinel)->next->number)
		ra(stack_a);
	else if (max == (stack_a->sentinel)->next->next->number)
		rra(stack_a);
	if ((stack_a->sentinel)->next->number > (stack_a->sentinel)->next->next->number)
		sa(stack_a);
	return (NULL);
}

/*
** Sort four elements by pushing min to B, sorting 3, then merging
*/
static t_singl	*sort_four(t_root *stack_a, t_root *stack_b, t_singl **singl)
{
	put_min_top(stack_a);
	if (check_sorted_s(stack_a) == 1)
		return (*singl);
	pb(stack_a, stack_b);
	sort_three(stack_a, singl);
	pa(stack_a, stack_b);
	return (*singl);
}

/*
** Push two smallest elements to stack B
*/
static void	push_two_smallest(t_root *stack_a, t_root *stack_b)
{
	put_min_top(stack_a);
	pb(stack_a, stack_b);
	put_min_top(stack_a);
	pb(stack_a, stack_b);
}

/*
** Sort remaining three elements and push back from B
*/
static void	merge_three_and_push_back(t_root *stack_a, t_root *stack_b)
{
	sort_three(stack_a, NULL);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*
** Sort five elements by pushing two smallest to B, sorting 3, then merging
*/
static t_singl	*sort_five(t_root *stack_a, t_root *stack_b, t_singl **singl)
{
	push_two_smallest(stack_a, stack_b);
	merge_three_and_push_back(stack_a, stack_b);
	return (*singl);
}

/*
** Main dispatcher for sorting 2-5 elements
** Selects appropriate sorting algorithm based on element count
*/
t_singl	*sort_under_five(int argc, t_root *stack_a)
{
	t_root	*stack_b;
	t_singl	*operation;

	operation = NULL;
	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (NULL);
	if (argc == 3)
		sort_two(stack_a, &operation);
	else if (argc == 4)
		sort_three(stack_a, &operation);
	else if (argc == 5)
		sort_four(stack_a, stack_b, &operation);
	else
		sort_five(stack_a, stack_b, &operation);
	cdll_clear(&stack_b, cdll_delone);
	return (operation);
}
