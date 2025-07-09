/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:39:39 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/09 18:34:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_singl	*lst_new(char *data)
{
	t_singl	*new_node;

	new_node = malloc(sizeof(t_singl));
	if (new_node == NULL)
		return (NULL);
	new_node->operation = data;
	new_node->next = NULL;
	return (new_node);
}
