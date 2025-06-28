/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-28 18:46:44 by tigarashi         #+#    #+#             */
/*   Updated: 2025-06-28 18:46:44 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_clear(t_singl **singl)
{
	t_singl	*tmp;

	if (singl == NULL || *singl == NULL)
		return ;
	while (*singl)
	{
		tmp = (*singl)->next;
		free(*singl);
		*singl = tmp;
	}
}