/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:05:45 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/04 10:44:50 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// ここで、ソートされていないstack_aを作る。
// mallocできなかったり、
#include <stdio.h>
t_root	*coordinate_compression(int *numbers, int *sorted_numbers, int len)
{
	int		i;
	int		index;
	t_root	*root;
	t_list	*node;

	root = ut_create_root();
	if (root == NULL)
		return (NULL);
	i = 0;
	root->node_len = len;
	while (i < len)
	{
		index = binary_search(sorted_numbers, numbers[i], len);
		if (i == 0)
			node = ut_create_first_node(root, index, false);
		else
			node = ut_create_node_back(root, index, false);
		if (node == NULL)
		{
			cdll_clear(&root, cdll_delone);
			return (NULL);
		}
		i++;
	}
	return (root);
}
