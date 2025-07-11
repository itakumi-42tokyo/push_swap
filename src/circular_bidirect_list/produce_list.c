/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:12:39 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/04 11:28:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

// ここでどのようにして、循環リストに挿入するか

t_list	*ut_create_node_back(t_root *root, int data, bool lis_f)
{
	t_list	*new_node;
	t_list	*sentinel;

	sentinel = root->sentinel;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->next = sentinel;
	new_node->prev = sentinel->prev;
	(sentinel->prev)->next = new_node;
	sentinel->prev = new_node;
	new_node->number = data;
	new_node->lis = lis_f;
	return (new_node);
}

t_list	*ut_create_node(t_root *root, int data, bool lis_f)
{
	t_list	*new_node;
	t_list	*sentinel;

	sentinel = root->sentinel;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->prev = sentinel;
	new_node->next = sentinel->next;
	(sentinel->next)->prev = new_node;
	sentinel->next = new_node;
	new_node->number = data;
	new_node->lis = lis_f;
	return (new_node);
}

t_root	*ut_create_root(void)
{
	t_root	*linked_list;

	linked_list = malloc(sizeof(t_root));
	if (linked_list == NULL)
		return (NULL);
	linked_list->node_len = 0;
	linked_list->lis_count = 0;
	linked_list->sentinel = malloc(sizeof(t_list));
	if (linked_list->sentinel == NULL)
	{
		free(linked_list);
		return (NULL);
	}
	(linked_list->sentinel)->prev = linked_list->sentinel;
	(linked_list->sentinel)->next = linked_list->sentinel;
	(linked_list->sentinel)->number = -1;
	(linked_list->sentinel)->lis = false;
	return (linked_list);
}

// sentinelの前に挿入して、new_nodeの前とつなげる
t_list	*ut_create_first_node(t_root *linked_list, int data, bool lis_f)
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
	node->lis = lis_f;
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
