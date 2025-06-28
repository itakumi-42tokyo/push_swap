/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:48:25 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 23:23:52 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	cdll_size(t_list *lst)
{
	int	length;

	length = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}

// t_list *create_new_node(void *data)
// {
// 	t_list *new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = data;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// int	main(void)
// {
// 	#include <stdio.h>
// 	char	*data[] = {"mario", "luigi", "Toad"};

// 	t_list *head = NULL;
// 	t_list *tail = NULL;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		t_list *new_node = create_new_node(ft_strdup(data[i]));
// 		if (head == NULL)
// 		{
// 			head = tail = new_node;
// 		}
// 		else
// 		{
// 			tail->next = new_node;
// 			tail = new_node;
// 		}
// 	}
// 	printf("%d", ft_lstsize(head));
// 	return (0);
// }
