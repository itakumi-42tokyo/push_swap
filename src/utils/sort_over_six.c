/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:26:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 14:03:06 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

#include <stdio.h>
t_singl	*sort_over_six(int argc, t_root *stack_a)
{
	t_list	*cur;

	find_lis(argc, stack_a);
	cur = stack_a->sentinel->next;
	
	return (0);
}
