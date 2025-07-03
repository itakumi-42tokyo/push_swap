/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 13:09:25 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>
t_singl	*sort_over_six(t_root *stack_a)
{
	t_list	*cur;

	judge_lis(stack_a);
	cur = stack_a->sentinel->next;
	while (cur != stack_a->sentinel)
	{
		printf("%d: %d\n", cur->number, cur->lis);
		cur = cur->next;
	}
	return (0);
}
