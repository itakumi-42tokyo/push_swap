/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_add_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:47:41 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 23:47:18 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	cdll_add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->prev = (*lst)->prev;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	#include <stdio.h>
//// t_list *lst = NULL means that content is nothing.
// 	t_list *lst = NULL;
// 	t_list *new = malloc(sizeof(new));
// 	if (!new)
// 		return (0);
// 	new->next = NULL;
// 	new->content = "Mr.suzuki";
// 	ft_lstadd_front(&lst, new);
// 	printf("%s", (char *)lst->content);
// 	return (0);
// }
