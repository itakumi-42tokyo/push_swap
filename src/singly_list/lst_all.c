/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-28 16:05:35 by tigarashi         #+#    #+#             */
/*   Updated: 2025-06-28 16:05:35 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_all(t_singl **head_node, char *data)
{
	t_singl	*new_node;

	if (head_node == NULL)
		return ;
	new_node = lst_new(data);
	if (new_node == NULL)
		return ;
	lst_add_back(head_node, new_node);
}