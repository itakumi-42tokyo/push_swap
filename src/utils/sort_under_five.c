/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:05:04 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

/*
** Sort two elements by swapping if needed
*/
static void	sort_two(t_root *stack_a)
{
	sa(stack_a);
}

/*
** Sort three elements using optimal rotation and swap
** Places max element in correct position first, then swaps if needed
*/
int	sort_three(t_root *stack_a)
{
	int	max;

	max = get_max(stack_a);
	if (max == (stack_a->sentinel)->next->number)
		ra(stack_a);
	else if (max == (stack_a->sentinel)->next->next->number)
		rra(stack_a);
	if ((stack_a->sentinel)->next->number
		> (stack_a->sentinel)->next->next->number)
		sa(stack_a);
	return (0);
}

/*
** Sort four elements by pushing min to B, sorting 3, then merging
*/
static void	sort_four(t_root *stack_a, t_root *stack_b)
{
	put_min_top(stack_a);
	if (check_sorted_s(stack_a) == 1)
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

/*
** Main dispatcher for sorting 2-5 elements
** Selects appropriate sorting algorithm based on element count
*/
int	sort_under_five(int argc, t_root *stack_a)
{
	t_root	*stack_b;

	stack_b = ut_create_root();
	if (stack_b == NULL)
		return (-1);
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		sort_four(stack_a, stack_b);
	else
		sort_five(stack_a, stack_b);
	cdll_clear(&stack_b, cdll_delone);
	return (0);
}
