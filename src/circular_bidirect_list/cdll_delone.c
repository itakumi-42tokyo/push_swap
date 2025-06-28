/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:51:07 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 22:31:06 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
// void	delete_content(void *something)
// {
// 	if (something == NULL)
// 		return ;
// 	free(something);
// }

void	cdll_delone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	t_list *node = malloc(sizeof(t_list));
// 	node->content = malloc(sizeof(char *) + 1);
// 	if (node->content == NULL)
// 		return (0);
// 	node->content = ft_strdup("go too far");
// 	node->next = NULL;
// 	void (*del)(void *);

// 	del = delete_content;
// 	ft_lstdelone(node, del);

// 	if ((node->content) == NULL)
// 		puts("yes");
// 	else
// 		printf("debug: %s", *(char *)node->content);
// 	return (0);
// }
