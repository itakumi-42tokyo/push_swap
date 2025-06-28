/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:49:57 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 18:36:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	cr_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
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
