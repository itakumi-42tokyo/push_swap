/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:50:25 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 21:47:30 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

// rootも消してほしい。
void	cdll_clear(t_root **root, void (*del)(t_list*))
{
	t_list	*current;
	t_list	*tmp;

	if (root == NULL || *root == NULL || del == NULL)
		return ;
	current = ((*root)->sentinel)->next;
	while (current != (*root)->sentinel)
	{
		tmp = current->next;
		del(current);
		current = tmp;
	}
	del((*root)->sentinel);
	free(*root);
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
// 	char *one = ft_strdup("walt for debby");
// 	char *two = ft_strdup("some day my prince will come");
// 	char *three = ft_strdup("moanin");
// 	void (*del)(void*);
// 	del = delete_content;
// 	t_list *lst = NULL;
// 	prepend(&lst, three);
// 	prepend(&lst, two);
// 	prepend(&lst, one);
// 	ft_lstclear((&lst), del);
// 	print_list(lst);
// 	return (0);
// }
