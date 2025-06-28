/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-28 15:54:26 by tigarashi         #+#    #+#             */
/*   Updated: 2025-06-28 15:54:26 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_singl	*lst_last(t_singl *head_node)
{
	if (head_node == NULL)
		return (NULL);
	while (head_node->next != NULL)
	{
	#include <stdio.h>
	printf("%p\n", head_node->next);
		head_node = head_node->next;
	}
	return (head_node);
}