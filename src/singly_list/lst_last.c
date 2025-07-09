/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:54:26 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/09 18:31:57 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_singl	*lst_last(t_singl *head_node)
{
	if (head_node == NULL)
		return (NULL);
	while (head_node->next != NULL)
	{
		head_node = head_node->next;
	}
	return (head_node);
}
