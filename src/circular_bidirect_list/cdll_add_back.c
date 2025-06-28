/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:49:57 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 16:22:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	cdll_add_back(t_root *linked_list, t_list *new)
{
	t_list	*last;
	t_list	*current;

	if (linked_list == NULL || linked_list->sentinel == NULL)
		return ;
	current = (linked_list->sentinel)->next;
	if (new == NULL)
		return ;
	if (current == NULL)
	{
		current = new;
		return ;
	}
	last = cdll_last(linked_list);
	last->next = new;
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
// 		printf("%s\n", ((char *)head->content));
// 		head = head->next;
// 	}
// }

// int	main(void)
// {
// 	char *one = "walt for debby";
// 	char *two = "some day my prince will come";
// 	char *three = "moanin";

// 	t_list *lst = NULL;
// 	t_list *new;
// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (0);
// 	new->content = "my favorite things";
// 	new->next = NULL;
// 	prepend(&lst, three);
// 	prepend(&lst, two);
// 	prepend(&lst, one);

// 	ft_lstadd_back(&lst, new);

// 	print_list(lst);

// 	return (0);
// }
