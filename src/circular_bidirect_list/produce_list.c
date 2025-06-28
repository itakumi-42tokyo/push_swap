/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:12:39 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 22:48:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

// ここでどのようにして、循環リストに挿入するか
t_list	*ut_create_node(t_root *root, int data)
{
	t_list	*new_node;
	t_list	*sentinel;
	t_list	*sentinel_prev;

	sentinel = root->sentinel;
	sentinel_prev = sentinel->prev;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	sentinel->prev = new_node;
	sentinel_prev->next = new_node;
	new_node->prev = sentinel_prev;
	new_node->next = sentinel;
	new_node->number = data;
	return (new_node);
}

t_root	*ut_create_root(void)
{
	t_root	*linked_list;

	linked_list = malloc(sizeof(t_root));
	if (linked_list == NULL)
		return (NULL);
	linked_list->node_len = 0;
	linked_list->sentinel = malloc(sizeof(t_list));
	if (linked_list->sentinel == NULL)
	{
		free(linked_list);
		return (NULL);
	}
	(linked_list->sentinel)->prev = linked_list->sentinel;
	(linked_list->sentinel)->next = linked_list->sentinel;
	(linked_list->sentinel)->number = 0;
	return (linked_list);
}

// sentinelの前に挿入して、new_nodeの前とつなげる
t_list	*ut_create_first_node(t_root *linked_list, int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	(linked_list->sentinel)->prev = node;
	(linked_list->sentinel)->next = node;
	(linked_list->sentinel)->number = 0;
	node->next = (linked_list)->sentinel;
	node->prev = (linked_list)->sentinel;
	node->number = data;
	return (node);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_root *root;

// 	root = ut_create_root();
// 	ut_create_first_node(root, 10);
// 	ut_create_node(root, 20);
// 	cdll_clear(&root, cdll_delone);
// 	if (root == NULL)
// 		return (1);
// 	return  (0);
// }
