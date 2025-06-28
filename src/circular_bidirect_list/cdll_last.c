/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:49:06 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 23:35:07 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*cdll_last(t_root *linked_list)
{
	t_list	*first_node;

	if (linked_list == NULL)
		return (NULL);
	first_node = (linked_list->sentinel)->next;
	while (first_node->next != linked_list->sentinel)
	{
		first_node = first_node->next;
	}
	return (first_node);
}

// void prepend(t_list **head, void	*data)
// {
// 	t_list *new_node = (t_list *)malloc(sizeof(t_list));
// 	new_node->content = data;
// 	new_node->next = *head;
// 	*head = new_node;
// }
// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	while (head != NULL)
// 	{
// 		printf("%d ", *((int *)head->content));
// 		head = head->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *head = NULL;

// 	int one = 1;
// 	int	two = 2;
// 	int	three = 3;
// 	prepend(&head, &three);
// 	prepend(&head, &two);
// 	prepend(&head, &one);

// 	// print_list(head);

// 	printf("%d", *((int *)(ft_lstlast(head)->content)));

// 	return (0);
// }
