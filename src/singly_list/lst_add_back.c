/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-28 15:50:24 by tigarashi         #+#    #+#             */
/*   Updated: 2025-06-28 15:50:24 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void    lst_add_back(t_singl **head_node, t_singl *new_node)
{
    t_singl	*last_node;

    if (head_node == NULL)
		return ;
	if (*head_node == NULL)
	{
		*head_node = new_node;
		return ;
	}
	last_node = lst_last(*head_node);
	last_node->next = new_node;
}