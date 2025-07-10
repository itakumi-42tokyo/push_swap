/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:00:02 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:03:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

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
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*
** Sort five elements by pushing two smallest to B, sorting 3, then merging
*/
void	sort_five(t_root *stack_a, t_root *stack_b)
{
	push_two_smallest(stack_a, stack_b);
	merge_three_and_push_back(stack_a, stack_b);
}
