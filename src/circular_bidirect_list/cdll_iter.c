/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:52:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 22:19:04 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// void	shift(unsigned char *c)
// {
// 	while (*c)
// 	{
// 		if (*c >= 126)
// 			*c = 32;
// 		else
// 			*c += 1;
// 		c++;
// 	}
// }
void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->number);
		lst = lst->next;
	}
}

// t_list *new_node(char *data)
// {
// 	t_list *node = malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->content = ft_strdup(data);
// 	node->next = NULL;
// 	return node;
// }
// #include <stdio.h>
// void	print_node(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	#include <stdio.h>

// 	void (*f)(void*);

// 	f = (void*)shift;

// 	t_list *head = NULL;
// 	t_list *tail = NULL;

// 	t_list *node1 = new_node("take");
// 	t_list *node2 = new_node("out");
// 	t_list *node3 = new_node("int");

// 	head = tail = node1;
// 	tail->next = node2; tail = node2;
// 	tail->next = node3; tail = node3;

// 	ft_lstiter(head, f);

// 	print_node(head);
// 	return (0);
// }
